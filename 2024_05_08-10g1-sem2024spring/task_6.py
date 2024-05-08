
def solve():

    with open(input()) as f:
        data = f.readlines()
        
    data = [s[:-1] for s in data]
    
    data = [s.replace('XVII', 'XVI VII').split() for s in data]
    
    words = []
    for s in data:
        words += s

    words = list(filter(lambda w: 'C' in w, words))

    if words:            
        mx_len = max(map(len, words))
        mx_words = filter(lambda w: len(w) == mx_len, words)
    else:
        mx_len = 0
    
    with open('output.txt', 'w') as f:
        print(mx_len, file=f)
        if mx_len:
            print(*mx_words, sep='\n', file=f)
        
       
solve()