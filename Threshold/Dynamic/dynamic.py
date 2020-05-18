import cv2 as cv
import numpy as np
from matplotlib import pyplot as plt


input_image = input('Enter the image: ')
img = cv.imread(input_image,0)

th = cv.adaptiveThreshold(img,255,cv.ADAPTIVE_THRESH_MEAN_C,\
            cv.THRESH_BINARY,7,15)

cv.imshow('Dynamcic', th)
cv.imshow('Original', img)

cv.waitKey(0)


