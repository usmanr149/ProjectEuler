#!usr/bin/env python

sum_sq = 0
zig = 10
for i in range(zig + 1):
	sum_sq += i**2
print sum_sq
diff = (zig*(zig + 1)/2)**2 - sum_sq
print diff