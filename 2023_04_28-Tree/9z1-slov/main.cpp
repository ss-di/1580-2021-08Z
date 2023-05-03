#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

template <typename T>
struct Node {
    T inf = T();
    int cnt = 1;
    Node *left = nullptr, *right = nullptr;
    Node(T z);
};

template <typename T>
Node<T>::Node(T z) {
    inf = z;
}

template <typename T>
struct Tree {
    Node<T> *root = nullptr;
    int size = 0;

    void Add(T el);
    void Add(T el, Node<T> *&r);

    void LKR();
    void LKR(Node<T> *&r);

    void Clear();
    void Clear(Node<T> *&r);

    Node<T> * Get(T el);
    Node<T> * Get(T el, Node<T> *&r);

    void Delete(T el);
    void Delete(T el, Node<T> *&r);

    vector<Node<T>> ToVector();
    void ToVector(Node<T> *&r, vector<Node<T>> & v);

    Tree();
    ~Tree();

};

template <typename T>
vector<Node<T>> Tree<T>::ToVector(){
    vector <Node<T>> v;
    ToVector(root, v);
    return v;
}
template <typename T>
void Tree<T>::ToVector(Node<T> *&r, vector<Node<T>> & v){
    if(r) {
        ToVector(r->left, v);
        v.push_back(*r);
        ToVector(r->right, v);
    }
}

template <typename T>
void Tree<T>::Add(T el){
    Add(el, root);
}

template <typename T>
void Tree<T>::Add(T el, Node<T> *&r){
    if(!r)
        r = new Node<T>(el);
    else if (el == r->inf)
        r->cnt += 1;
    else if (el < r->inf)
        Add(el, r->left);
    else
        Add(el, r->right);
}

template <typename T>
Node<T> * Tree<T>::Get(T el){
    return Get(el, root);
}

template <typename T>
Node<T> * Tree<T>::Get(T el, Node<T> *&r){
    if(!r)
        return nullptr;
    else if (el == r->inf)
        return r;
    else if (el < r->inf)
        return Get(el, r->left);
    else
        return Get(el, r->right);
}

template <typename T>
void Tree<T>::LKR(){
    LKR(root);
//    cout << '\n';
}

template <typename T>
void Tree<T>::LKR(Node<T> *&r){
    if(r) {
        LKR(r->left);
        cout << r->inf << ' ' << r->cnt << '\n';
        LKR(r->right);
    }
}

template <typename T>
void Tree<T>::Clear(){
    Clear(root);
}

template <typename T>
void Tree<T>::Clear(Node<T> *&r){
    if(r) {
        Clear(r->left);
        Clear(r->right);
        delete r;
        r = nullptr;
    }
}

template <typename T>
void Tree<T>::Delete(T el){
    Delete(el, root);
}

template <typename T>
void Tree<T>::Delete(T el, Node<T> *&r){
    if(r) {
        if (el == r->inf) {
            if (!r->left) {
                Node<T> * tmp = r;
                r = r->right;
                delete tmp;
            } else if (!r->right) {
                Node<T> * tmp = r;
                r = r->left;
                delete tmp;
            } else {
                Node<T> * tmp = r->left;
                while (tmp->right)
                    tmp = tmp->right;
                r->inf = tmp->inf;
                r->cnt = tmp->cnt;
                Delete(tmp->inf, r->left);
            }
        } else if (el < r->inf)
           Delete(el, r->left);
        else
           Delete(el, r->right);
    }
}

template <typename T>
Tree<T>::Tree(){
}

template <typename T>
Tree<T>::~Tree(){
    Clear();
}

ostream & operator << (ostream & out, pair<int, string> const & p)
{
    out << p.second << " " <<  p.first;
    return out;
}

bool operator < (pair<int, string> const & a, pair<int, string> const & b)
{
    return a.first > b.first || (a.first == b.first && a.second < b.second);
}



int main()
{
    ifstream f("input.txt");
    string s;
    Tree <string> t;
    while (f >> s)
        //cout << s << '\n';
        t.Add(s);
    f.close();

    //t.LKR();
    vector<Node<string>> v;
    v = t.ToVector();

    Tree <pair<int, string>> t2;

    for (auto x : v)
        //cout << x.inf<<' ' << x.cnt<<'\n';
        t2.Add(make_pair(x.cnt, x.inf));

    //t2.LKR();

    vector<Node<pair<int, string>>> v2;
    v2 = t2.ToVector();

    ofstream f2("output.txt");

    for (auto x : v2)
        f2 << x.inf.second << ' ' << x.inf.first << '\n';

    f2.close();
    return 0;
}
