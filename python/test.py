#!/home/kamano/anaconda3/bin/python
# -*- coding: utf-8 -*-
import sys
import os
import xml.etree.ElementTree as ET

args = sys.argv
#os.chdir('/BANK/PMC/20170527/articles/Plant_Physiol_Biochem')
#tree = ET.parse('/BANK/PMC/20170527/articles/Plant_Physiol_Biochem/PMC3185291.nxml')
tree = ET.parse(args[1])
root = tree.getroot()
elm = root.find(".//*[@sec-type='results']")
print('+++tostring(elm)+++')
print(ET.tostring(elm))
print('+++elm.text+++')
print(elm.text)
print('+++elm.html+++')
print(elm.xml)

