#include <iostream>
#include <string>
using namespace std;

#define ull unsigned long long
#define l long
#define s string
#define np string::npos

// 012345
// 123+45+1

l calc(s st){
    
    ull p = st.find_last_of("+-");
    if (p == np)
        return stol(st);

    return (calc(st.substr(0, p)) + stol(st.substr(p)));
    
}

int main(){
    
    s st;
    cin >> st;
    cout << calc(st);
    return 0;    
}
