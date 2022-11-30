#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long
#define ll long long
#define npos string::npos
#define v_l vector<long>
#define v2_l vector<vector<long>>
#define v2_lnm(name, row_count, col_count) vector<vector<long>> name(row_count, vector<long>(col_count));

#define v_d vector<double>
#define v2_d vector<vector<double>>
#define v2_dnm(name, row_count, col_count) vector<vector<double>> name(row_count, vector<double>(col_count));

#define f(n) for (int _ = 0; _ < n; _ += 1)
#define fi(i, n) for (long i = 0; i < long(n); i += 1)

#define all(x) x.begin(), x.end()

void dfs(const v2_l &m, v_l u, long n, long k, long v, long s, v2_l &ans){
    if (u[v])
        return;
    if (!k) {
        ans[s][v] = 1;
        return;
	}
    u[v] = true;
    fi(i, n)
        if (m[v][i])
            dfs(m, u, n, k-1, i, s, ans);
    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long n;
    cin >> n;
    
    v2_lnm(m, n, n);
    v2_lnm(ans, n, n);
    
    for (auto &v: m) for (auto &el: v) cin >> el;
    
    long k;
    cin >> k;
    
    fi(i, n){
		v_l u(n);
        dfs(m, u, n, k+1, i, i, ans);
	}
    
    bool zero = 1;
    for(long i = 0; i < n; i+= 1)
        for(long j = i + 1; j < n; j+= 1)
            if (ans[i][j]) {
				zero = 0;
				cout << i+1 << " " << j+1 << '\n';
			}

    if (zero)
        cout << 0;

    return 0;
}
