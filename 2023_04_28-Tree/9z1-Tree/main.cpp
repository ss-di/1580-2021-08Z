#include <iostream>

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

    Tree();
    ~Tree();

};

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
    cout << '\n';
}

template <typename T>
void Tree<T>::LKR(Node<T> *&r){
    if(r) {
        LKR(r->left);
        cout << r->inf << ' ';
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
        cout << "del " << r->inf<<'\n';
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
    cout << "Hello" << '\n';
}

template <typename T>
Tree<T>::~Tree(){
    cout << "Bye" << '\n';
    Clear();
}


int main()
{
    Tree<int> t;
    t.Add(10);
    t.Add(8);
    t.Add(9);
    t.Add(91);
    t.Add(19);
    t.LKR();
    if (t.Get(9))
        cout << "YES\n";
    else
        cout << "NO\n";

    t.Get(19)->inf += 1; //но так нельзя
    t.Delete(10);
    t.LKR();

    Tree<string> t2;
    t2.Add("asd");
    t2.Add("aa");
    t2.LKR();

    cout << "Hello world!" << endl;
    return 0;
}
