# 動かない
# 白枠で縁取られた面積最大の領域を探す
import cv2
from PIL import Image
import numpy

l_img_f = '20170114200617-bc.png'
l_img = Image.open(l_img_f)
image, contours, hierarchy = cv2.findContours(l_img,cv2.RETR_CCOMP,cv2.CHAIN_APPROX_SIMPLE)
# contours, hierarchy = cv2.findContours(l_img,cv2.RETR_CCOMP,cv2.CHAIN_APPROX_SIMPLE)
contourImg = cv2.cvtColor(l_img, cv2.COLOR_GRAY2BGR)
bgr_total = contourImg.copy()

inner_contours = []
for index, contour in enumerate(contours):
    if hierarchy[0][index][2] == -1:
        inner_contours.append(contour)

approxes = []
max_box = None
for contour in inner_contours:
    # 矩形補完
    epsilon = 0.01*cv2.arcLength(contour,True)
    approx = cv2.approxPolyDP(contour,epsilon,True)
    area = cv2.contourArea(approx)

    if max_box is None or cv2.contourArea(max_box) < cv2.contourArea(approx):
        max_box = approx
    if(area > 20):
        approxes.append(approx)
        x,y,w,h = cv2.boundingRect(contour)
