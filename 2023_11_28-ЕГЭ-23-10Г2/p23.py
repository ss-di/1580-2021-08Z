dp = [0] * 21
dp[1] = 1
for i in range(2, 20+1):
    if i % 2 == 0:
        dp[i] = dp[i-1] + dp[i // 2]
    else:
        dp[i] = dp[i-1]
        
print(dp[20])

dp = [0] * 21
dp[1] = 1
for i in range(2, 10+1):
    if i % 2 == 0:
        dp[i] = dp[i-1] + dp[i // 2]
    else:
        dp[i] = dp[i-1]
dp[:10] = [0] * 10
print(dp)
for i in range(11, 20+1):
    if i % 2 == 0:
        dp[i] = dp[i-1] + dp[i // 2]
    else:
        dp[i] = dp[i-1]
print(dp[20])

def calc(f, t):
#    if f == 9:
#        return 0
    if f > t:
        return 0
    if f == t:
        return 1
    return calc(f+1, t) + calc(f*2, t)
    
print(calc(1, 20))
print(calc(1, 10) * calc(10, 20))