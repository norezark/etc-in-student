#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import requests
import cv2

url = input()
r = requests.get(url)
with open('image.jpg', 'wb') as f:
    f.write(r.content)

img = cv2.imread('image.jpg')

img = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY)
ret, outimg = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)

cv2.imwrite('image.jpg', outimg)
