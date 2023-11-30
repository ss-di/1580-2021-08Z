dp = [0] * 21

dp[1] = 1
for i in range(2, 20+1):
    if i % 2 != 0:
        dp[i] = dp[i-1]
    else:
        dp[i] = dp[i-1] + dp[i // 2]
        
print(dp)
print(dp[20])
######################################################
dp = [0] * 21

dp[1] = 1
for i in range(2, 10+1):
    if i % 2 != 0:
        dp[i] = dp[i-1]
    else:
        dp[i] = dp[i-1] + dp[i // 2]
        
print(dp)
dp[:10] = [0] * 10
for i in range(11, 20+1):
    if i % 2 != 0:
        dp[i] = dp[i-1]
    else:
        dp[i] = dp[i-1] + dp[i // 2]
print(dp)
print(dp[20])
########################################################

def rec(f, t):
#    if f == 10:
#        return 0
    if f > t:
        return 0
    if f == t:
        return 1
    return rec(f + 1, t) + rec(f * 2, t)

print(rec(1, 20))
print(rec(1, 10) * rec(10, 20))

