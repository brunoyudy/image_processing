from __future__ import print_function
from __future__ import division
import cv2 as cv
import argparse
import numpy as np


def thresholding(img):
    img2 = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    img_reshaped = img.reshape((-1,3)) #reshape to 1 feature format

    Z = np.float32(img_reshaped) #transform to float32

    criteria = (cv.TERM_CRITERIA_EPS + cv.TERM_CRITERIA_MAX_ITER, 10, 1.0) #stopping when achieve 10 iterations OR 1.0 accuracy
    ret, label, center = cv.kmeans(Z, 2 , None, criteria, 10, cv.KMEANS_RANDOM_CENTERS) #iterative algorithm to cluster
    '''
    Z[label == 0] = [255,255,255] #binary thresholding the image using the labeled clusters
    Z[label == 1] = [0,0,0]

    Z2 = Z.reshape((len(img), len(img[0]))) #reshape to the original format

    output = np.uint8(Z2)
    cv.imshow('Number of Clusters', output)
    '''
    a = len(img2)
    b = len(img2[0])
    img2 = img2.reshape((len(img2)*len(img2[0]), 1))
    img2[label == 0] = 0
    img2[label == 1] = 255
    #print(len(img2))
    img2 = img2.reshape((a, b))
    #print(len(img2))
    img2 = np.uint8(img2)
    return img2
