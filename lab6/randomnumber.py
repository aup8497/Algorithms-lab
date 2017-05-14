from random import randint

a=[]

for i in xrange(0,1000000):
	a.append(randint(0,1000))

for i in xrange(0,1000000):
	print a[i] 

