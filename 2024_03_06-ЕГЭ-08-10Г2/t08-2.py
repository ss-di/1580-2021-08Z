s = 'ПРИВЫЧКА'
s = sorted(s)

print(s)

import itertools
allperm = itertools.permutations(s)
print(list(allperm))


allprod = itertools.product(s, repeat=5)
allprod = list(allprod)
print(allprod)

print(len(allprod))

for i in range(len(allprod)-1, -1, -1):
    if (i+1) % 5 == 0:
        del allprod[i]
print(len(allprod))

for i in range(len(allprod)):
    if 'А' not in allprod[i] and 'И' not in allprod[i] and 'Ы' not in allprod[i] and len(set(allprod[i])) == 5:
        
        print(i+1)
        break