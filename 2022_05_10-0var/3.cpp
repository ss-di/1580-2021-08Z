#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
    long mx, a;
    string s;
    cin >> s;
    ifstream f(s);
    f >> mx;
    while (f >> a)
        if (a > mx)
            mx = a;
    f.close();
    cout << mx;
    return 0;
}
