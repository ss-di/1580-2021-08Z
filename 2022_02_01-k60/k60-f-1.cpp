#include <iostream>
#include <string>
using namespace std;

#define ull unsigned long long
#define l long
#define s string
#define np string::npos

// 012345
// +45

l calc(s st){

    ull p = st.find_first_of("+-");
    if (p == np)
        return stol(st);

    l res = stol(st.substr(0, p));
    st.erase(0, p);
    
    while (true) {
        p = st.find_first_of("+-", 1);
        if (p == np)
            return res+stol(st);
        res += stol(st.substr(0, p));
        st.erase(0, p);
    }
}

int main(){
    
    s st;
    cin >> st;
    cout << calc(st);
    return 0;    
}
