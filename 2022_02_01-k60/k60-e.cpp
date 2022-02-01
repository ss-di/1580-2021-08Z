#include <iostream>
#include <string>
using namespace std;

#define ull unsigned long long
#define l long
#define s string
#define np string::npos
#define fn(n) for(l i = 0; i < n; i = i + 1)

s get_new(s st){
    s ns = "";
    
    while(st != "") {
        s fs = st.substr(0, 1);
        ull p = st.find_first_not_of(fs);
        if (p == np)
            p = st.size();
        ns += to_string(p) + fs;
        st.erase(0, p);
    }
    
    return ns;
}

int main(){

    int k;
    cin >> k;
    s st = "1";
    fn(k - 1)
        st = get_new(st);
    cout << st;
    return 0;    
}
