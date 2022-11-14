
# task1

import cv2
import numpy as np
# brg
colored = cv2.imread("colored.jpg", cv2.IMREAD_COLOR)
cv2.imshow("task1-1", colored)
# cv2.destroyWindow("task1-1")
# bgr
blue = colored.copy()
blue[:, :, 1] = 0
blue[:, :, 2] = 0
cv2.imshow("task1-2", blue)


green = colored.copy()
green[:, :, 0] = 0
green[:, :, 2] = 0
cv2.imshow("task1-3", green)

red = colored.copy()
red[:, :, 0] = 0
red[:, :, ] = 0
cv2.imshow("task1-4", red)
cv2.waitKey(0)
