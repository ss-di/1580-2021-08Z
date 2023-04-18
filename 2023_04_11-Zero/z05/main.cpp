#include <iostream>
#include <vector>

using namespace std;

int summ(const vector<int> &v){
    int s = 0;
    for(auto x: v)
        s += x;
    return s;
}

void swap(vector<int> &a, vector<int> &b){
    vector<int> tmp = a;
    a = b;
    b = tmp;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
