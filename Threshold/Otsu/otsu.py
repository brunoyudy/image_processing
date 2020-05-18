import cv2 as cv
import numpy as np 
from matplotlib import pyplot as plt

input_image = input('Enter the image: ')
img = cv.imread(input_image, 0)

ret1, th1 = cv.threshold(img, 0, 255, cv.THRESH_BINARY+cv.THRESH_OTSU)

cv.imshow("Otsu", th1)
cv.waitKey(0)
