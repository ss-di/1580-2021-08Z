def calc_lines(s):
    v = sorted(s)
    v.append(v[-1] + 10)
    cnt_points = 0
    cnt_lines = 0
    for c in range(len(v)-1):
        cnt_points += 1
        if v[c] + 1 != v[c+1]:
            if cnt_points >= 3:
                cnt_lines += 1
            cnt_points = 0
    return cnt_lines

def solve(name):

    with open(input()) as f:
        n, m = int(f.readline()), int(f.readline())
        d = dict()
        for _ in range(n):
            r, c = map(int, f.readline().split())
            d[r] = d.pop(r, set()) | set([c])
        
    mx_cnt = -1
    for r in sorted(d.keys()):
        d[r] = calc_lines(d[r])
        if d[r] >= mx_cnt:
            mx_cnt = d[r]
            mx_row = r
            
    print(mx_cnt, mx_row)
    
solve(input())