from k_means import thresholding
import cv2
import numpy as np

img = cv2.imread('image2.png', 1)

def nothing(x):
    pass

cv2.namedWindow('image')

cv2.createTrackbar('MinArea', 'image', 0, 10000, nothing)
cv2.createTrackbar('MaxArea', 'image', 0, 10000, nothing)
cv2.createTrackbar('MinConvexity', 'image', 0, 100, nothing)
cv2.createTrackbar('MaxConvexity', 'image', 0, 100, nothing)
cv2.createTrackbar('MinCircularity', 'image', 0, 100, nothing)
cv2.createTrackbar('MaxCircularity', 'image', 0, 100, nothing)
cv2.createTrackbar('MinThreshold', 'image', 0, 255, nothing)
cv2.createTrackbar('MaxThreshold', 'image', 0, 255, nothing)
'''
cv2.createTrackbar('MinInertiaRatio', 'image', 0, 100, nothing)
cv2.createTrackbar('MaxInterniaRatio', 'image', 0, 100, nothing)
'''

while(1):
    params = cv2.SimpleBlobDetector_Params()
    params.filterByColor = False
    params.blobColor = 0
    params.filterByCircularity = True
    params.filterByConvexity = True
    #params.filterByInertia = True
    params.minArea = cv2.getTrackbarPos('MinArea', 'image')
    params.maxArea = cv2.getTrackbarPos('MaxArea', 'image')
    params.minConvexity = cv2.getTrackbarPos('MinConvexity', 'image')/100
    params.maxConvexity = cv2.getTrackbarPos('MaxConvexity', 'image')/100
    params.minCircularity = cv2.getTrackbarPos('MinCircularity', 'image')/100
    params.maxCircularity = cv2.getTrackbarPos('MaxCircularity', 'image')/100
    params.minThreshold = cv2.getTrackbarPos('MinThreshold', 'image')
    params.maxThreshold = cv2.getTrackbarPos('MaxThreshold', 'image')
    '''
    params.minInertiaRatio = cv2.getTrackbarPos('MinInertiaRatio', 'image')/100
    params.maxInertiaRatio = cv2.getTrackbarPos('MaxInertiaRatio', 'image')/100
    '''
    detector = cv2.SimpleBlobDetector_create(params)
    keypoints = detector.detect(img)
    counter = len(keypoints)
    im_with_keypoints = cv2.drawKeypoints(img, keypoints, np.array([]), (0,0,255), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
    cv2.imshow('Blobs', im_with_keypoints)
    k = cv2.waitKey(1) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
