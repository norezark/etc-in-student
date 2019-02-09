#!/usr/bin/env/ python3
# -*- coding: utf-8 -*-

moto = int(input('元金を入力してください(単位:円)>'))
nenri = int(input('年利を入力してください(単位:％)>'))

for i in range(10):
    moto = round( moto * (1 + nenri/100) )
    print(str(i) + '年後：貯金は' + str(moto) + '円になりました。')
