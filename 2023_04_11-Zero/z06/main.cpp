#include <iostream>
#include <vector>

using namespace std;

void vvod(vector<int> &v, int &n){
    int x;
    while (cin >> x)
        v.push_back(x);
    n = v.size() - 1;
}

int get_min_len(const vector<int> &v, int n){
    int mn_len = 0, len = 0;
    for (int i = 0; i < n; i += 1)
        if (v[i] % 10 == v[i] / 10 % 10)
            len += 1;
        else {
            if (len > 1 && (len < mn_len || mn_len == 0))
                mn_len = len;
            len = 0;
        }
    if (len > 1 && (len < mn_len || mn_len == 0))
        mn_len = len;
    return mn_len;
}


int main()
{
    int n;
    vector<int> v;
    vvod(v, n);
    cout << get_min_len(v, n);
    return 0;
}
