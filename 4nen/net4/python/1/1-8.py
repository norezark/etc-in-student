#!/usr/bin/env/ python3
# -*- coding: utf-8 -*-

strs = input().split()

print(' '.join(sorted(strs, key = lambda x: len(x))))
