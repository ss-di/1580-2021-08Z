#include<iostream>

using namespace std;

long gcd(long a, long b){
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main(){
    long n, a, b, gcd_ab, sum = 0;
    bool flag = false;
    cin >> n;
    for (long i = 0; i < n; i += 1){
        cin >> a >> b;
        //lcm = a * gcd(a, b) / b;
        gcd_ab = gcd(a, b);
        if (gcd_ab % 2 != 0) {
            sum += gcd_ab;
            flag = true;
        }
    }
    if (flag)
        cout << sum;
    else
        cout << -1;
    return 0;
}
