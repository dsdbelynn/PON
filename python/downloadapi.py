import requests
import os
import numpy
import datetime

with open('league.txt','r',encoding='utf-8') as f:
    content = f.read()

txtload_array = numpy.loadtxt('./apitypelist.txt',dtype=str)
a=0
b = len(txtload_array)

while a<b:
    url='https://poe.ninja/api/data/'+txtload_array[a,0]+'overview?league='+content+'&type='+txtload_array[a,1]
    myfile = requests.get(url)
    savepath=os.getcwd()+'\\ninjaapi\\'+txtload_array[a,1]+'.json'
    open(savepath,'wb').write (myfile.content)
    a=a+1

savepath=os.getcwd()+'\\ninjaapi\\apidata.txt'
now=datetime.datetime.now()
open(savepath,'w').write (now.strftime("%Y-%m-%d %H:%M:%S")+content)
