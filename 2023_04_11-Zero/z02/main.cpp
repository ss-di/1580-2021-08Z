#include <iostream>

using namespace std;

int main()
{
    int n, mn_m=-1, kol = 0, h, m;
    cin >> n;
    for (int i = 0; i < n; i += 1){
        cin >> h >> m;
        m += h*60;
        if (m < mn_m || mn_m == -1){
            mn_m = m;
            kol = 1;
        } else if (m == mn_m)
            kol += 1;
    }
    cout << mn_m / 60 << " " << mn_m % 60 << '\n';
    if (kol == 1)
        cout << "мер";
    else
        cout << kol << " дю";
    return 0;
}
