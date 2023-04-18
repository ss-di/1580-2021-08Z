#include <iostream>
#include <string>
#include <sstream>

using namespace std;

bool check(string s){
    for (int i = 0; i < int(s.size())-1; i += 1)
        if (s.find(s.substr(i, 1), i+1) != string::npos)
            return false;
    return true;
}

bool ok1(string s){
    stringstream ss(s);
    string word;
    while (ss >> word)
        if (check(word))
            return true;
    return false;
}

bool ok(string s){
    s += ' ';
    string word;
    while (!s.empty()){
        if (s[0] == ' ')
            s.erase(0, 1);
        else {
            int p = s.find(' ');
            word = s.substr(0, p);
            s.erase(0, p+1);
            if (check(word))
                return true;
        }
    }
    return false;
}


int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
