#include <iostream>

using namespace std;


bool f(int s, int t, int a){
    return s >= 2*t || a < s+t;
}

int YES(int a){
    int cnt = 0;
    cnt += int(f(1, 2, a));
    cnt += int(f(11, 2, a));
    cnt += int(f(1, 12, a));
    cnt += int(f(11, 12, a));
    cnt += int(f(-11, -12, a));
    cnt += int(f(-11, 12, a));
    cnt += int(f(-12, 11, a));
    cnt += int(f(10, 10, a));
    cnt += int(f(10, 5, a));
    return cnt;
}

int main()
{
    int a = 1000;
    while (YES(a) != 6)
        a -= 1;
    cout <<a << YES(a);
    return 0;
}
