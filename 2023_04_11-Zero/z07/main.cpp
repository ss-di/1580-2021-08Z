#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

void vvod(vector<string> &v, int &n){
    cin >> n;
    v.resize(n);
    string s;
    getline(cin, s);
    for (int i = 0; i < n; i += 1)
        getline(cin, v[i]);
}


void get_name_kol(const string &s, string &dat, int &kol){
    stringstream ss(s);
    ss >> dat;

    vector<int> izm;
    int x, sum = 0;
    while (ss >> x) {
        izm.push_back(x);
        sum += x;
    }
    double sr = double(sum) / izm.size();

    kol = 0;
    for(auto x: izm)
        if (fabs(x - sr) > 10)
            kol += 1;
}


string get_dat(const vector<string> &v, int n){
    string mx_dat = "аномалий нет", dat;
    int mx_kol = 0, kol;
    for (int i = 0; i < n; i += 1){
        get_name_kol(v[i], dat, kol);
        if (kol > mx_kol){
            mx_kol = kol;
            mx_dat = dat;
        }
    }
    return mx_dat;
}

int main()
{
    int n;
    vector<string> v;
    vvod(v, n);
    cout << get_dat(v, n);
    return 0;
}
