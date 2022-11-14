import cv2; import numpy as np

#BRG
img = cv2.imread("./colored.jpg",cv2.IMREAD_COLOR)
cv2.imshow("task1", img)

#Blue
# img = cv2.imread("colored.jpg",cv2.IMREAD_REDUCED_COLOR_2)
print ( type(img))


# cv2.imshow("task1 - Blue", img)

# cv2.waitKey(0)