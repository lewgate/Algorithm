#coding=utf-8
#!/usr/bin/python

import random

def MatchCount(len):
	item = range(0, len)
	items = range(0, len)
	random.shuffle(items)
	count = 0
	for i in range(0, len):
		if items[i] == item[i]:
			count+=1
	return count

total = 0
print 'start'
for j in range(0, 1000):
#	print j
	total = total+MatchCount(10000)

print float(total)/1000

