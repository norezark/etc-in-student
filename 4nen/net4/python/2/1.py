#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import csv

with open('customers.csv', 'r') as f:
    reader = csv.reader(f)
    header = next(reader)

    c = 0
    for row in reader:
        if row[6] == '神奈川県':
            c += 1

    print(c)
