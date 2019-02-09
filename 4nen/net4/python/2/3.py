#!/usr/bin/env python3
# -*- coding: utf-8 -*-

import cv2

img = cv2.imread('sample.jpg')

ret, outimg = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY)

cv2.imwrite('sample.jpg', outimg)
