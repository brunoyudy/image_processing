import cv2
import numpy as np
from matplotlib import pyplot as plt


def MeanThreshold(image):
    pixels = len(image)*len(image[0]) #get the number of pixels
    soma = 0

    for rows in range(len(image)):
        soma += sum(image[rows]) #sum the pixel value over the entire image

    threshold = soma/pixels #the mean of pixel values is set as the threshold
    ret, dst = cv2.threshold(image, threshold,255,cv2.THRESH_BINARY) #applying the global threshold
    cv2.imshow("Threshold", dst)
    cv2.imshow("Original: ", image)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    return 0


image = input("Enter the image: ")
img = cv2.imread(image, 0)

MeanThreshold(img)


