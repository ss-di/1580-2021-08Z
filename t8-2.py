
def check(x):
    for c in x:
        if c in "ИЫА":
            return False
    
    for c in x:
        if x.count(c) != 1:
            return False
            
    return True       
    
    #return len(x) == len(set(x))
    
s = "ПРИВЫЧКА"
s = sorted(s)

import itertools
v = list(itertools.product(s, repeat=5))
print(v[:10])
for i in range(len(v)-1, -1, -1):
    if (i+1) % 5 == 0:
        del v[i]
        
for i in range(len(v)):
    if check(v[i]):
        print(i+1, v[i])
        break
