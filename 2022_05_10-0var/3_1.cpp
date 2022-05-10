#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main(){
    long mx, a;
    bool flag = false;
    string s;
    cin >> s;
    ifstream f(s);
    while (f >> a)
        if (a < 0 && (a > mx || !flag)) {
            mx = a;
            flag = true;
        }
    f.close();
    cout << mx;
    return 0;
}
