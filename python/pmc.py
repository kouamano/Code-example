#!/home/kamano/anaconda3/bin/python

import os
import xml.etree.ElementTree as ET
#os.chdir('/BANK/PMC/20170527/articles/Plant_Physiol_Biochem')
tree = ET.parse('/BANK/PMC/20170527/articles/Plant_Physiol_Biochem/PMC3185291.nxml')
root = tree.getroot()
elm = root.find(".//*[@sec-type='results']")
print(ET.tostring(elm))

