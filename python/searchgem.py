import json

def resolveJson():

    file = 'ninjaapi/SkillGem.json'
    f_obj = open(file)
    number = json.load(f_obj)

    findname='Seismic Trap'

    i=0
    while i<len(number['lines']):
        if (findname)==(number['lines'][i]['name']):

            print(' ')
            print(number['lines'][i]['name'])


            print("Corrupted?",end=" ")
            print('corrupted' in number['lines'][i].keys(),end=" ")


            if('gemLevel' in number['lines'][i].keys()):
                print("gemLevel",end=" ")
                print(number['lines'][i]['gemLevel'],end=" ")


            if('gemQuality' in number['lines'][i].keys()):
                print("gemQuality",end=" ")
                print(number['lines'][i]['gemQuality'])


            print("chaosValue",end=" ")
            print(number['lines'][i]['chaosValue'])
            print(' ')
        i=i+1
    
resolveJson()
