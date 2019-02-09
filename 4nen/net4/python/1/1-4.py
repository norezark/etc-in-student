#!/usr/bin/env/ python3
# -*- coding: utf-8 -*-

print('試験点数を入力して下さい。(1行1データ。負の数で入力終了)')
datas = []

while True:
    data = int(input('点数>'))
    if data < 0:
        break
    else:
        datas += [data]

print('平均点=' + str( sum(datas) / len(datas) ) + '点')
print('最高点=' + str( max(datas) ) + '点')
print('最低点=' + str( min(datas) ) + '点')
