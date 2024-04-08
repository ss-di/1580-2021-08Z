
s = "ШКОЛА"
ans = 0
'''
for c1 in s:
    for c2 in s:
        for c3 in s:
            res = c1+c2+c3
            if res.count('К') == 1:
                ans += 1
print(ans)
'''

import itertools
v = list(itertools.product(s, repeat=3))
# print(v)
for res in v:
    if res.count('К') == 1:
        ans += 1
print(ans)

ans = 0
v = list(itertools.permutations(s))
print(v)
for res in v:
    if str(res).find('О') < str(res).find('А'):
        ans += 1
print(ans)

print(str([1, 2]))
