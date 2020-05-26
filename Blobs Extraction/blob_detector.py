import cv2
import numpy as np

im = cv2.imread('image.png', 0)
params = cv2.SimpleBlobDetector_Params()
params.filterByColor = False
params.minThreshold = 65
params.maxThreshold = 93
params.blobColor = 0
params.minArea = 10
params.maxArea = 5000
params.filterByCircularity = True
params.filterByConvexity = True
params.minConvexity = 0
params.maxConvexity = 1.0
params.minCircularity = 0
params.maxCircularity = 1.0
detector = cv2.SimpleBlobDetector_create(params)
keypoints = detector.detect(im)
im_with_keypoints = cv2.drawKeypoints(im, keypoints, np.array([]), (0,0,255), cv2.DRAW_MATCHES_FLAGS_DRAW_RICH_KEYPOINTS)
cv2.imshow("Keypoints", im_with_keypoints)
cv2.waitKey(0)