s = 'ШКОЛА'
'''
cnt = 0
for c1 in s:
    for c2 in s:
        for c3 in s:
            res = c1+c2+c3
            if res.count('К') == 1:
                cnt += 1
print(cnt)
'''

'''                    
for c1 in s:
    s2 = s[:s.find(c1)]+s[s.find(c1)+1:]
    for c2 in s2:
        s3 = s2[:s2.find(c2)]+s2[s2.find(c2)+1:]
        for c3 in s3:
            s4 = s3[:s3.find(c3)]+s3[s3.find(c3)+1:]
            for c4 in s4:
                s5 = s4[:s4.find(c4)]+s4[s4.find(c4)+1:]
                for c5 in s5:
                    res = c1+c2+c3+c4+c5
                    print(res)
'''


import itertools
allperm = itertools.permutations(s)
print(list(allperm))


allprod = itertools.product(s, repeat=3)
print(list(allprod))