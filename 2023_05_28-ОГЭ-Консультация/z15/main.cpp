#include <iostream>

using namespace std;

int main()
{
    int n, cnt = 0, a, b, c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        if (a >= 100 || b >= 100 || c >= 100)
            cnt += 1;
    }
    cout << cnt;
    return 0;
}
