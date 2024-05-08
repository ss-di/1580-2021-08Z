n = int(input())

d = dict()

for _ in range(n):
    name, summ = input().split()
    summ = int(summ)
    
    d[name] = d.pop(name, 0) + summ
    
mx_summ = -1

for k in d.keys():
    if d[k] > mx_summ:
        mx_summ = d[k]
        mx_name = k
        
print(mx_name)