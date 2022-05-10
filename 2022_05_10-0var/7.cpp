#include<iostream>
#include<vector>

using namespace std;

// ====
void swap(long &a, long &b) {
    long tmp = a;
    a = b;
    b = tmp;
}

void obmen(vector <long> &v, long p1, long p2) {
    swap(v[p1], v[p2]);
}

long mx(const vector <long> &v) {
    long ans = 0;
    for (long i = 1; i < long(v.size()); i += 1)
        if (v[i] >= v[ans])
            ans = i;
    return ans;
}
// ====

void vivod(const vector <long> &v) {
    for (long i = 0; i < long(v.size()); i += 1)
        cout << v[i] << " ";
}

int main(){
    vector <long> v {1, 22, 33, 4444, 533, 36};
    obmen(v, 2, 4);
    vivod(v);
    cout << mx(v);
    return 0;
}
