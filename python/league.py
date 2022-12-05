import json

def resolveJson():

    file = 'getleague.json'
    f_obj = open(file)
    number = json.load(f_obj)
    res = []


    i=0
    for id in number:
        x=number[i]['id']
        print(x)
        i=i+1



    
resolveJson()
