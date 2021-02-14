a=int(input())
b=int(input())
l=0
r=1
while(r**a<=b):
	l=r
	r=r*2
while(l<r):
	cur=(l+r)//2
	if (cur**a<=b):
		l=cur+1
	else:
		r=cur
print(l)
