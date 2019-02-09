#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import requests
import re

url = input()
r = requests.get(url)

with open('image', 'wb') as f:
    f.write(r.content)
