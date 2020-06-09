import cv2 as cv
import numpy as np

kernel2 = np.ones((70,70),np.uint8)

src = cv.imread('image4.png', 0)

_,src = cv.threshold(src,127,255,cv.THRESH_BINARY_INV)
opening1 = cv.morphologyEx(src, cv.MORPH_OPEN, kernel2)

cv.imshow("Output", opening1)
cv.waitKey(0)


'''
ret,src = cv.threshold(src,100,255,cv.THRESH_TRUNC)

window_name = ('Sobel Demo - Simple Edge Detector')
scale = 1
delta = 0
ddepth = cv.CV_16S

_,img = cv2.threshold(img,127,255,cv2.THRESH_BINARY)
flip = cv2.flip(img, 1)
edgesx = cv2.Sobel(img, cv2.CV_64F, 1, 0, ksize = 5)
edgesx_flip = cv2.Sobel(flip, cv2.CV_64F, 1, 0, ksize = 5)
edgesx_flip = cv2.flip(edgesx_flip, 1)

edgesy = cv2.Sobel(img, cv2.CV_64F, 0, 1, ksize = 5)

edges = edgesx + edgesy

edges = np.zeros((len(edgesx), len(edgesx[0]), 1), np.uint8)

for i in range(len(edgesx)):
    for j in range(len(edges[0])):
        if (edgesx[i][j] >127 or edgesx_flip[i][j] > 127):
            edges[i][j] = 255


cv2.imshow('EdgesX', edgesx)
cv2.imshow('EdgesX Flipped', edgesx_flip)
cv2.imshow('Edges', edges )
cv2.waitKey(0)

src = cv.GaussianBlur(src, (3, 3), 0)
        
        
grad_x = cv.Sobel(src, ddepth, 1, 0, ksize=3, scale=scale, delta=delta, borderType=cv.BORDER_DEFAULT)
# Gradient-Y
#grad_y = cv.Scharr(src,ddepth,0,1)
grad_y = cv.Sobel(src, ddepth, 0, 1, ksize=3, scale=scale, delta=delta, borderType=cv.BORDER_DEFAULT)
        
abs_grad_x = cv.convertScaleAbs(grad_x)
abs_grad_y = cv.convertScaleAbs(grad_y)
        
        
grad = cv.addWeighted(abs_grad_x, 1.0, abs_grad_y, 1.0, 0)
        
        
cv.imshow(window_name, grad)
k = cv.waitKey(10000) & 0xFF
if k == 27:
    destroyAllWindows()

'''