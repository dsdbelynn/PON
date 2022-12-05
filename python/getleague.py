import http.client

conn = http.client.HTTPSConnection("api.pathofexile.com")
payload = ''
headers = {
   'User-Agent': 'Apifox/1.0.0 (https://www.apifox.cn)'
}
conn.request("GET", "/leagues", payload, headers)
res = conn.getresponse()
data = res.read()
print(data.decode("utf-8"))