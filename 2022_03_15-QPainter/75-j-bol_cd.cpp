#include <bits/stdc++.h>

#define fn(n) for (long _ = 0; _ < n; _ += 1)
#define fin(i, n) for (i = 0; i < n; i += 1)

using namespace std;

int main() {
    
    long a;
    vector<long> v;

    while (cin >> a)
        v.push_back(a);

    long n = long(v.size()) - 1;
    long k = v.back();
    v.resize(n);
    
    k = (n - k % n) % n;
    
    long st = 0;
    long cur = st;
    a = v[st];
    long next = (cur + k) % n;
    fn(n) {
        if (next != st) {
            v[cur] = v[next];
            cur = next;
            next = (next + k) % n;
        } else {
            v[cur] = a;
            st += 1;
            cur = st;
            a = v[st];
            next = (cur + k) % n;
        }
    }
    
    long i;
    fin(i, n) {
        cout << v[i] << " ";
    }
        
	return 0;
}

