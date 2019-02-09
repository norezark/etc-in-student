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
sock.listen(1)

memos = []

onRun = True
while onRun:
    # クライアントからの接続を待つ。
    # 接続されたらそのクライアントのアドレスがaddrに入り、
    # addrとの通信用ソケットとしてconnが作られる。
    conn, addr = sock.accept()
    print('クライアントが接続しました', addr)

    try:
        while True:
            data = conn.recv(bufsize)
            try:
                data = data.decode('utf-8').strip()
            except UnicodeDecodeError as msg:
                print(msg)
                conn.close()
                sys.exit(1)
            print('クライアントからの文字列: ', data)
            data = data.split()
            command = data[0].lower()
            if command == 'see':
                ans = ''
                for i, memo in enumerate(memos):
                    ans += '[{}] {}\n'.format(i, memo)
                conn.sendall(ans.encode('utf-8'))
            elif command == 'add':
                memos.append(data[1])
            elif command == 'del':
                memos.pop(int(data[1]))
            elif command == 'exit':
                break
            elif command == 'shutdown':
                onRun = False
                break
    except OSError as msg:
        print(msg)
        conn.close()
        sys.exit(1)

    # クライアントとの接続を閉じる
    print('通信終了')
    conn.close()

# 待ち受け用ソケットを閉じる
sock.close()
