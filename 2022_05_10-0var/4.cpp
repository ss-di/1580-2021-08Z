#include<iostream>
#include<string>

using namespace std;

void work(string &s){
    string alf = "abcdefghijklmnopqrstuvwxyz";
    long p;
    for (long i = long(s.size()) - 1; i >= 0; i -= 1)
        if (s[i] >= 'a' && s[i] <= 'z') {
            p = alf.find(s.substr(i, 1));
            s.insert(i, alf.substr(0, p));
        }
}

int main(){
    string s;
    getline(cin, s);
    work(s);
    cout << s;
    return 0;
}
