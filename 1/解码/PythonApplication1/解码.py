#!-*- coding:utf-8 -*-
import os
import requests
from io import BytesIO
from pyzbar import pyzbar
from PIL import Image,ImageEnhance
 
 
def get_ewm(img_adds):
    """ 读取二维码的内容： img_adds：二维码地址（可以是网址也可是本地地址 """
    img = Image.open(img_adds)
 
    # img.show()  # 显示图片，测试用
 
    txt_list = pyzbar.decode(img)
 
    for txt in txt_list:
        barcodeData = txt.data.decode("utf-8")
        print(barcodeData)
 
if __name__ == '__main__':
    # 解析本地二维码
    get_ewm('D://image//1.jpg')