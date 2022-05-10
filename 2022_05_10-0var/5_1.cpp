#include<iostream>
#include<string>

using namespace std;

struct River {
   string name;
   long inflow = 0;
};


River split(string s) {
    River r;
    r.name = s.substr(0, s.find("_"));
    r.inflow = stol(s.substr(s.find("_") + 1));
    return r;
}

int main(){
    string s;
    River cur, ans;
    cin >> s;
    ans = split(s);
    while (cin >> s) {
        cur = split(s);
        if (cur.inflow >= ans.inflow)
            ans = cur;
    }
    cout << ans.name;
    return 0;
}
