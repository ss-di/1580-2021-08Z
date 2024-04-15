a = 192
b = 168
c = 32
d = 128

a2 = bin(a)[2:]
b2 = bin(b)[2:]
c2 = bin(c)[2:]
d2 = bin(d)[2:][:2]

print(a2)
print(b2)
print(c2)
print(d2)

s = a2.count('1') + b2.count('1') + c2.count('1') + d2.count('1')

print(s)
cnt = 0
for i in range(2**6):
    i2 = bin(i)[2:]
    if i2.count('1') %2 != 0:
        cnt += 1
        
print(cnt)