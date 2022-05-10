#include<iostream>

using namespace std;

long isEqual(long a){
    a = labs(a);
    long d = a % 10;
    // a = a / 10;
    while (a != 0){
        if (d != a % 10)
           return false;
        a = a / 10;
    }
    return true;
}

int main(){
    long a, cnt = 0;
    cin >> a;
    while (a != 0) {
        if (isEqual(a))
            cnt += 1;
        cin >> a;
    }
    if (cnt != 0)
        cout << cnt;
    else
        cout << -1;
    return 0;
}
