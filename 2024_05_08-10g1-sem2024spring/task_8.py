n, m = map(int, input().split())

vv = [list(map(int, input().split())) for _ in range(n)]

sums = [sum(v) for v in vv]

mx_sum = max(sums)

mx_row = n - 1

while sums[mx_row] != mx_sum:
    mx_row -= 1
    
ans = list(filter(lambda x: x % 15 == 10, vv[mx_row]))

print(len(ans))