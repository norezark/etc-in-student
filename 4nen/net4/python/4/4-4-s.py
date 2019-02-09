#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import socket
import sys
import random

port = 10025      # サーバのポート番号(学生番号+10000にすること)
bufsize = 4096    # 比較的小さな2の累乗にする

# ソケットを作る
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

# ソケットsockを待ち受け用ソケットにする
sock.bind(('', port))
sock.listen(2)

onRun = True
while onRun:
    answer = random.randint(1, 20)
    print('answer = ' + str(answer))

    # クライアントからの接続を待つ。
    # 接続されたらそのクライアントのアドレスがaddrに入り、
    # addrとの通信用ソケットとしてconnが作られる。
    connA, addr = sock.accept()
    print('クライアントAが接続しました', addr)
    connB, addr = sock.accept()
    print('クライアントBが接続しました', addr)

    try:
        connA.sendall('数字を入力してください\n'.encode('utf-8'))
        connB.sendall('数字を入力してください\n'.encode('utf-8'))
        dataA = connA.recv(bufsize)
        dataB = connB.recv(bufsize)
        try:
            dataA = dataA.decode('utf-8').strip()
            dataB = dataB.decode('utf-8').strip()
        except UnicodeDecodeError as msg:
            print(msg)
            conn.close()
            sys.exit(1)
        print('クライアントAからの文字列: ', dataA)
        print('クライアントBからの文字列: ', dataB)
        if dataA == 'shutdown' or dataB == 'shutdown':
            onRun = False
            continue

        xA = int(dataA)
        xB = int(dataB)
        ansA = ''
        ansB = ''
        if xA == xB:
            ansA = 'Draw\n'
            ansB = 'Draw\n'
        elif abs(xA - answer) < abs(xB - answer):
            ansA = 'Win\n'
            ansB = 'Lose\n'
        else:
            ansA = 'Lose\n'
            ansB = 'Win\n'
        connA.sendall(ansA.encode('utf-8'))
        connB.sendall(ansB.encode('utf-8'))
    except OSError as msg:
        print(msg)
        connA.close()
        connB.close()
        sys.exit(1)

    # クライアントとの接続を閉じる
    print('通信終了')
    connA.close()
    connB.close()
else:
    print('通信終了')
    connA.close()
    connB.close()


# 待ち受け用ソケットを閉じる
sock.close()
