#!/usr/bin/python

MAX=10*1000*1000+1
p = []
for i in range(0, MAX):
    p.append(1)

p[0] = p[1] = 0
i = 2

while True:
    j = i
    print i
    while (j + i) < MAX:
        p[j + i] = 0
        j = j + i

    j = i
    while j + 1 < MAX and p[j + 1] == 0:
        j = j + 1
    if j + 1 == MAX:
        break
    i = j + 1
