import json

def resolveJson():

    file = 'ninjaapi/Currency.json'
    f_obj = open(file)
    number = json.load(f_obj)

    findname='Mirror of Kalandra'

    i=0
    while i<len(number['lines']):
        if (findname)==(number['lines'][i]['currencyTypeName']):
            print(number['lines'][i]['currencyTypeName'])
            print(number['lines'][i]['chaosEquivalent'])
        i=i+1
    
resolveJson()
