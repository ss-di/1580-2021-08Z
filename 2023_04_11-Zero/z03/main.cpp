#include <iostream>

using namespace std;


bool check(string s) {
    int gl = 0, sog = 0;
    string g = "aeyuio";
    for (int i = 0; i < int(s.size()); i += 1)
        if (g.find(s[i]) != string::npos)
            gl += 1;
        else
            sog += 1;
    return gl < sog;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
