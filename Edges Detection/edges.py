import cv2
import numpy as np

original = cv2.imread('image.jpeg', 0)
img = cv2.imread('image.jpeg', 0)

def nothing(x):
    pass



cv2.namedWindow('Edges', cv2.WINDOW_NORMAL)
cv2.createTrackbar('Thresh Value', 'Edges', 0, 255, nothing)
cv2.createTrackbar('Min Value', 'Edges', 0, 100, nothing)
while(1):
    value = cv2.getTrackbarPos('Thresh Value', 'Edges')
    minVal = cv2.getTrackbarPos('Min Value', 'Edges')
    ret,thresh3 = cv2.threshold(img,value,255,cv2.THRESH_TRUNC)
    edges = cv2.Canny(thresh3, minVal, minVal*3)
    cv2.imshow('Edges', np.hstack((original,thresh3,edges)))
    #cv2.imshow('Trunc Threshold', thresh3)
    k = cv2.waitKey(1) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()

'''
img = cv2.GaussianBlur(img, 5)

cv2.namedWindow('Edges', cv2.WINDOW_NORMAL)

cv2.createTrackbar('MinVal', 'Edges', 0, 300, nothing)

while(1):
    minVal = cv2.getTrackbarPos('MinVal', 'Edges')
    edges = cv2.Canny(img, minVal, minVal*3)
    cv2.imshow('Edges', edges)
    k = cv2.waitKey(1) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
'''
