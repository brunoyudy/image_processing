import cv2
import numpy as np
from matplotlib import pyplot as plt


def MeanThreshold(image):
    print("ROWS: " , len(image))
    print("COLUMNS: " ,len(image[0]))
    pixels = len(image)*len(image[0])
    soma = 0
    for rows in range(len(image)):
        soma += sum(image[rows])
    print(soma)
    threshold = soma/pixels
    print('Threshold: ',threshold)
    ret, dst = cv2.threshold(image, threshold,255,cv2.THRESH_BINARY_INV)
    cv2.imshow("Threshold", dst)
    cv2.imshow("Original: ", image)
    cv2.imwrite('MeanBrightnessPython2.png', dst)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    return 0

img = cv2.imread('tooth_displaced.png', 0)



#print(sum(img[0]))
MeanThreshold(img)


