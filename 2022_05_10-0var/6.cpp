#include<iostream>
#include<vector>

using namespace std;

// ====
void swap(long &a, long &b) {
    long tmp = a;
    a = b;
    b = tmp;
}

double sr(long a) {
    if (a == 0)
        return 0;
    a = labs(a);
    long sum = 0, cnt = 0;
    while (a != 0) {
        cnt += 1;
        sum += a % 10;
        a = a / 10;
    }
    return double(sum) / cnt;
}

void sort(vector <long> &v) {
    for (long i = 0; i < long(v.size()) - 1; i += 1)
        for (long j = 0; j < long(v.size()) - 1 - i; j += 1)
            if (sr(v[j]) > sr(v[j + 1]))
                swap(v[j], v[j + 1]);
}
// ====

void vivod(const vector <long> &v) {
    for (long i = 0; i < long(v.size()); i += 1)
        cout << v[i] << " ";
}

int main(){
    vector <long> v {1, 22, 33, 4444, 533, 36};
    sort(v);
    vivod(v);
    return 0;
}
