import cv2
import numpy as np

cap = cv2.VideoCapture(0)

while True:
    _, frame = cap.read()
    frame2 = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)
    laplacian = cv2.Laplacian(frame, cv2.CV_64F)
    sobelx = cv2.Sobel(frame2, cv2.CV_64F, 1, 0, ksize = 5)
    sobely = cv2.Sobel(frame, cv2.CV_64F, 1, 0, ksize = 5)

    cv2.namedWindow('laplacian', cv2.WINDOW_NORMAL)
    cv2.imshow('original', frame)
    cv2.imshow('laplacian', laplacian)
    cv2.imshow('sobelx', sobelx)
    cv2.imshow('sobely', sobely)

    k = cv2.waitKey(5) & 0xFF
    if k == 27:
        break

cv2.destroyAllWindows()
cap.release()