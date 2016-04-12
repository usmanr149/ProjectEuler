#!usr/bin/env python
from PrimeCheck import CheckPrime

for i in range(2, 101):
	if(CheckPrime(i) == 1):
		print(i)