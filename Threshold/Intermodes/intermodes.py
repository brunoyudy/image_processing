import cv2
import numpy as np 
from matplotlib import pyplot as plt
import seaborn as sns

input_image = input('Enter the image: ')
image = cv2.imread(input_image, 0)
pixel_values = image.reshape((len(image)*len(image[0]),1))


#get the all the points of a smoothed distribution of pixel values
x,y = sns.distplot(pixel_values, hist = False, kde = True, kde_kws = {'linewidth': 3}, label = 'tooth').get_lines()[0].get_data() 

pos_peak1 = 0 #index of the first local max
pos_peak2 = len(y)-1 #index of the second local max

for i in range(len(y)): #getting the index of the first local max value comparing with the neighborhood
    if i<len(y) - 1:
        if y[i+1] > y[i]: 
            pos_peak1 = i

for i in range(len(y)): #getting the index of the second local max value comparing with the neighborhood
    if i<len(y) - 1:
        if y[len(y) - 1 - i] < y[len(y) - 2 - i]:
            pos_peak2 = len(y) - 2 - i

peak1 = x[pos_peak1] #values of the 2 most common intensity of pixels in the image
peak2 = x[pos_peak2]

threshold = (peak1 + peak2)/2

ret, dst = cv2.threshold(image, threshold,255,cv2.THRESH_BINARY)

cv2.imshow("Intermodes", dst)
cv2.waitKey(0)
