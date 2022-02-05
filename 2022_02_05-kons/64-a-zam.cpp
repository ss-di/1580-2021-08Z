#include <iostream>
using namespace std;

string zam(string s, string f, string t){
    unsigned long long p;

    p = s.find(f);
    while (p != string::npos){
        s.replace(p, f.size(), t);
        p = s.find(f, p + t.size());
    }
    return s;
}

int main() {
    string s, f, t;
    getline(cin, s);
    getline(cin, f);
    getline(cin, t);
    cout << zam(s, f, t);
	return 0;
}

/*
abcbc
abc
aaa
===
aaabc
*/
