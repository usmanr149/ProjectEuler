#!usr/bin/env python

def CheckPrime(a):
	half = int(a**0.5)

	for i in range(2, half+1):
		if(a%i == 0):
			return 0
	return 1