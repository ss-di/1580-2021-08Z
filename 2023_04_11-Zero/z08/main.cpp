#include <iostream>
#include <vector>

using namespace std;

void vvod(vector<int> &v, int &n){
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i += 1)
        cin >> v[i];
}

int calc_sum(const vector<int> &v, int b, int e){
    int s = 0;
    for (int i = b; i <= e; i += 1)
        s += v[i];
    return s;
}

int get_max_len1(const vector<int> &v, int n){
    int mn_len = -1, mx_sum = -1, sum, len;
    for (int b = 0; b < n; b += 1)
        for (int e = b; e < n; e += 1) {
            sum = calc_sum(v, b, e);
            len = e - b + 1;
            if (sum % 43 == 0 && sum > mx_sum) {
                mx_sum = sum;
                mn_len = len;
            } else if (sum == mx_sum && len < mn_len)
                mn_len = len;
        }
    return mn_len;
}

void get_max_len_from_begin(const vector<int> &v, int n, int b, int &mx_sum, int &mn_len){
    int sum = 0, len;
    for (int e = b; e < n; e += 1) {
        sum += v[e];
        len = e - b + 1;
        if (sum % 43 == 0 && sum > mx_sum) {
            mx_sum = sum;
            mn_len = len;
        } else if (sum == mx_sum && len < mn_len)
            mn_len = len;
    }
}

int get_max_len(const vector<int> &v, int n){
    int mn_len = -1, mx_sum = -1;
    for (int b = 0; b < n; b += 1)
        get_max_len_from_begin(v, n, b, mx_sum, mn_len);
    return mn_len;
}

int main()
{
    int n;
    vector<int> v;
    vvod(v, n);
    cout << get_max_len(v, n);
    return 0;
}
