#include <iostream>
#include <vector>
using namespace std;

double calcMult(const vector<vector<double>> &a){
//---
double res = 1;
int n = int(a.size());
for(int i = 0; i < n; i += 1) {
    res *= a[i][i];
    if (n % 2 == 0 || i != n / 2)
        res *= a[i][n-i-1];
}
return res;
//---
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
