import cv2 
import numpy as np
# np.set_printoptions(formatter={'int':hex})

blc3 = cv2.imread("../assets/3x3black.bmp", 1)
rgb4 = cv2.imread("../assets/4x4rgb.bmp", cv2.IMREAD_UNCHANGED)
rgb5 = cv2.imread("../assets/5by5rgb.bmp" , 1)
blc6 = cv2.imread("../assets/6x6black.bmp" , 1)
rgb6 = cv2.imread("../assets/6x6_24bit.bmp" , 1 )
grass_blocks = cv2.imread("../assets/wanted_back.bmp" , cv2.IMREAD_UNCHANGED)
me = cv2.imread("../assets/real_me_whiteBack.jpeg" , cv2.IMREAD_UNCHANGED)


#color order is bgr

#gray scale NON weghited #

#( constant : each color is 1/3 of its original value )
# gray_grass = np.zeros((grass_blocks.shape[0] , grass_blocks.shape[1]) , dtype=np.uint8)
# gray_grass = (grass_blocks[:,:,0] + grass_blocks[:,:,1] + grass_blocks[:,:,2] ) / 3 
# gray_grass = gray_grass.astype('uint8')
# #in one line numpy !!! common at least 10 lines in cpp
# cv2.imshow("grass_gray" , gray_grass)

#weighted gray scale#

#(eye more sensitive  to green , thus give green more weight)
gray_me = np.zeros((me.shape[0] , me.shape[1]) , dtype=np.uint8)
gray_me = (me[:,:,0] * 0.114 ) + (me[:,:,1] * 0.587 ) + (me[:,:,2] * 0.299)  
gray_me = gray_me.astype('uint8')
#  you could do int div '//' but dtype would also need change to np.uint8
cv2.imshow("gray_me" , gray_me)



print (f"this image is is green then blue then red top to down \n BLUE - GREEN  - RED \n\n {gray_me}\n\n original \n\n\n  {me} \n\n")
# print ( f" shape of rgb4  (rws , cols , clr)\n(cv2 def is BGR)= : {rgb6.shape}" , rgb6.size + 54,"bytes total")
# print(f"1st :\n {blc3}\n \n 2nd : \n {rgb4} \n\n 3rd : \n {rgb5} 4th : \n\n {rgb6} \n\n 5th : \n {blc6}")
# cv2.imshow("tst1" , blc3)
# cv2.imshow("tst2" , rgb4)
# cv2.imshow("tst3" , rgb5)
# cv2.imshow("tst4" , blc6)
# cv2.imshow("tst5" , rgb6)

 
cv2.waitKey(30000)
cv2.destroyAllWindows()# #not actuallty needed here but it's a good practicec:\Users\OmarPc\repo_CHROMA_BMP_proj\testing\ref_bmphead.h~