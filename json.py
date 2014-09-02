#coding utf-8
import sys
import json

print "hello world"


f = file("./ocb1.dat", "r")

s = f.readline()

count = 0

while s:
    
    my_json = json.loads(s)
    
    count += 1
    print my_json["ads_id"]    
    
    
    s = f.readline()

f.close()

print "total line = %d" % count
