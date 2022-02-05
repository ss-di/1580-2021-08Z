#include <iostream>
#include <string>
using namespace std;

void perebor(int k, string alf, string cur, int &cnt) { 
    if (k == 0) { // k == cur.size()
        cout << cur << '\n';
        cnt += 1;
    } else {
        for (int i = 0; i < int(alf.size()); i += 1)
            perebor(k-1, alf, cur + alf.at(i), cnt);  
    }
}

int main() {
    int k, cnt = 0;
    string a;
    cin >> a;
    cin >> k;
    perebor(k, a, "", cnt);
    cout << cnt;
    return 0;
}
