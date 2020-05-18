from __future__ import print_function
from __future__ import division
import cv2 as cv
import argparse
import numpy as np


#defining trackbar parameters
alpha_slider_max = 10
title_window = 'Number of Clusters'
trackbar_name = 'clusters'


def kmeans_threshold(val):

    img_reshaped = img.reshape((len(img)*len(img[0]), 1)) #reshape to 1 feature format

    Z = np.float32(img_reshaped) #transform to float32

    criteria = (cv.TERM_CRITERIA_EPS + cv.TERM_CRITERIA_MAX_ITER, 10, 1.0) #stopping when achieve 10 iterations OR 1.0 accuracy
    ret, label, center = cv.kmeans(Z, val , None, criteria, 10, cv.KMEANS_RANDOM_CENTERS) #iterative algorithm to cluster
    Z[label == 0] = 0 #binary thresholding the image using the labeled clusters
    Z[label == 1] = 64

    Z2 = Z.reshape((len(img), len(img[0]))) #reshape to the original format

    output = np.uint8(Z2)
    cv.imshow('Number of Clusters', output)


img = cv.imread('tooth.png', 0)


#initializing trackbar
cv.namedWindow(title_window)
cv.createTrackbar(trackbar_name, title_window, 0, alpha_slider_max, kmeans_threshold)

kmeans_threshold(2)

cv.waitKey()
