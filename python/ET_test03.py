#!/home/kamano/anaconda3/bin/python
# -*- coding: utf-8 -*-
import sys
import os
import re
import xml.etree.ElementTree as ET

args = sys.argv
tree = ET.parse(args[1])
root = tree.getroot()
print('+++++')
for e in root.findall(".//sec"):
  e.attrib
  #tostring(e.attrib)
  #print(e.attrib)
  print(type(e.attrib)," ; ",e.attrib)
  #print(e.attrib.items())
  #print(e.attrib['sec-type'])
  print(type(e.attrib['sec-type'])," ; ",e.attrib['sec-type'])
  #if re.match(r".*",e.attrib['sec-type']):
  if re.match(r"result",e.attrib['sec-type'],re.IGNORECASE):
    print("M")
  #flag = re.match(r".*","y")
  #flag = re.match(r".*",e.attrib)
  #if flag:
    #print(e.attrib)
print('+++++')
for e in root.findall(".//*[@sec-type='results']"):
  print(e.tag,e.attrib)
  #print("+"+e.text+"+")
print('+++++')
for e in root.findall('.//*[@sec-type="*sult*"]'):
  print(e.attrib)

