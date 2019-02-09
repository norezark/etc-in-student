#!/usr/bin/env/ python3
# -*- coding: utf-8 -*-

for i in range(1, 41):
    if (i % 3 == 0) or ('3' in str(i)):
        i = '(' + str(i) + ')'

    print(i, end=' ')

print()
