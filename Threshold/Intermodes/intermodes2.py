import cv2
import numpy as np 
from matplotlib import pyplot as plt

def preprocessing(image):
    pixel_values = image.reshape((len(image)*len(image[0]),1))
    return pixel_values

def get_number_of_pixels(pixel_values):     #return the number of pixels per each value

    number_of_pixels = []
    unique, counts = np.unique(pixel_values, return_counts=True)

    return counts

def smoothing(number_of_bins, number_of_pixels):  #return a smoothed list of the parameter

    smoothed_values = []
    values_per_interval = int(256/number_of_bins)

    for i in range(number_of_bins):
        smoothed_values.append(np.mean(number_of_pixels[i*values_per_interval : (i+1)*values_per_interval]))

    return values_per_interval, smoothed_values

def get_peaks(smoothed_values):    #return de peaks, vector of positions of all local max
    peaks = []
    for i in range(len(smoothed_values)):
        if( i == 0 ):
            if(smoothed_values[i] > smoothed_values[i+1]):
                peaks.append(i)

        elif (i == len(smoothed_values) - 1):
            if(smoothed_values[i] > smoothed_values[i-1]):
                peaks.append(i)

        else:
            if (smoothed_values[i] > smoothed_values[i - 1] and smoothed_values[i] > smoothed_values[i+1]):
                peaks.append(i)
    return peaks

def thresholding(image):
    pixel_values = preprocessing(image)
    number_of_pixels = get_number_of_pixels(pixel_values)
    possible_bins = [256, 128, 64, 32, 16, 8, 4, 2]
    for i in possible_bins:
        values_per_interval, smoothed_values = smoothing(i, number_of_pixels)
        peaks = get_peaks(smoothed_values)
        if (len(peaks) == 2):
            break
    threshold_value = (peaks[0] + peaks[1])*values_per_interval / 2
    print("values per interval: " , values_per_interval)
    print("peak1: " , peaks[0])
    print("peak2: " , peaks[1])
    print("threshold value: " , threshold_value)
    ret, dst = cv2.threshold(image, threshold_value,255,cv2.THRESH_BINARY)
    cv2.imshow("Intermodes", dst)
    cv2.waitKey(0)


image = cv2.imread('tooth_displaced.png', 0)
thresholding(image)
