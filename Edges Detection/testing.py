import cv2
import numpy as np

kernel = np.ones((7,7), np.uint8)

def get_gradients(vector):
    output = []
    for i in range(len(vector)-1):
            gradient = int(int(vector[i+1])) - int(vector[i-1])
            output.append(gradient)
    return output

def get_neighbor(sorted_vector,pos):
    #print('len pos', len(pos))
    counter = 0
    for j in range(len(pos)-2):
        value = sorted_vector[-1]
        #print('Value: ', value)
        for i in range(len(pos)):
            distance = get_distance(value[0], pos[i][0], value[1], pos[i][1])
            if(-1 <= distance[0] <= 1 and -1 <= distance[1] <= 1):
                print(counter)
                counter+=1
                if([pos[i][0], pos[i][1]] not in sorted_vector):
                    sorted_vector.append([pos[i][0], pos[i][1]])
    for i in pos:
        if(i not in sorted_vector):
            print(i)
    print('len sorted_vector', len(sorted_vector))
    return sorted_vector

def get_distance(x1, x2, y1, y2):
    distance = [x1 - x2, y1 - y2]
    return distance

img = cv2.imread('image6.png', 0)


ret, thresh = cv2.threshold(img, 127, 255, cv2.THRESH_BINARY_INV)
img2 = cv2.cvtColor(thresh, cv2.COLOR_GRAY2BGR)

contours, hieararchy = cv2.findContours(thresh, 1, 2)

cnt = contours[1]

(x,y), radius = cv2.minEnclosingCircle(cnt)
center = (int(x), int(y))
radius = int(radius) - 12  
cv2.circle(img2, center,radius,(200,0,0), 0)

feature = img2[:,:, 0]
rows, cols = np.where(feature == 200)

pos = []
for i in range(len(rows)):
    pos.append([rows[i], cols[i]])

sorted_pixels = [pos[0]]
print(sorted_pixels)

print('len0',len(pos))

sorted_vector = get_neighbor(sorted_pixels, pos)


vector = []

for i in range(len(sorted_vector)):
    vector.append(thresh[sorted_vector[i][0]][sorted_vector[i][1]])
    thresh[sorted_vector[i][0]][sorted_vector[i][1]] = 127

gradients = get_gradients(vector)

counter = 0
for i in range(len(gradients)):
    if(gradients[i] != 0):
        img2 = cv2.circle(img2, (sorted_vector[i][1], sorted_vector[i][0]), 0, (0,255,0), 4)
        counter += 1

print(len(pos))

cv2.namedWindow('Output', cv2.WINDOW_NORMAL) 
cv2.imshow('Output', img2)
cv2.namedWindow('thresh', cv2.WINDOW_NORMAL)
cv2.imshow('thresh', thresh)
cv2.waitKey(0)

