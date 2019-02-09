#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import socket
import sys

host = "127.0.0.1"
port = 10025
bufsize = 4096      # 比較的小さな2の累乗にする

# ソケットを作る
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# タイムアウト時間を秒単位で設定する
sock.settimeout(3)

# サーバへ接続する
try:
    sock.connect((host, port))
except OSError as msg:
    print(msg)
    sys.exit(1)

# サーバに文字列を送る
data = input("please input a price> ")
sock.sendall(data.encode('utf-8'))

# サーバから文字列を受け取る
msg = sock.recv(bufsize)
msg = msg.decode('utf-8')
print('(Received) the price tax included =', msg)

# 接続を切る
sock.close()
