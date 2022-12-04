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

void dfs(const v2_l &m, v_l &u, long n, long k, long v, long s, long &ans){
    if (!k && v == s) {
        ++ans;
        return;
	}
    if (u[v])
        return;
    if (!k) {
        return;
	}
    u[v] = true;
    fi(i, n)
        if (m[v][i])
            dfs(m, u, n, k-1, i, s, ans);
    u[v] = false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long n;
    cin >> n;
    
    v2_lnm(m, n, n);
    
    for (auto &v: m) for (auto &el: v) cin >> el;
    
    long k;
    cin >> k;

    long ans = 0;
    fi(i, n) {
		v_l u(n);
        dfs(m, u, n, k, i, i, ans);
	}
    
    cout << ans / k;

    return 0;
}
