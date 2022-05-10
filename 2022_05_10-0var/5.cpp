#include<iostream>
#include<string>

using namespace std;

string name(string s) {
    return s.substr(0, s.find("_"));
}

long cnt(string s) {
    return stol(s.substr(s.find("_") + 1));
}

int main(){
    string s, ans;
    cin >> ans;

    while (cin >> s)
        if (cnt(s) >= cnt(ans))
            ans = s;

    cout << name(ans);
    return 0;
}
