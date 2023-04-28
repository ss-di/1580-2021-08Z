#include <iostream>

using namespace std;

struct Node {
    int inf = 0;
    Node *left = nullptr, *right = nullptr;
    Node(int el);
};

Node::Node(int el) {
    inf = el;
}

struct Tree {
    Node *root = nullptr;

    void Addint(int el);
    void Add(int el);
    void Add(Node *&root, int el);
    void LKP();
    void LKP(Node *root);
    void Clear();
    void Clear(Node *root);
    bool Find(int el);
    bool Find(Node *root, int el);
    Tree();
    ~Tree();

};

Tree::Tree() {
    cout << "Hello" << '\n';
}

Tree::~Tree() {
    Clear();
    cout << "Bye" << '\n';
}

void Tree::Addint(int el){
    if (!root)
        root = new Node(el);
    else {
        Node *tmp = root;
        bool fl = true;
        while (fl)
            if (el < tmp -> inf && tmp -> left)
                tmp = tmp -> left;
            else if (el >= tmp -> inf && tmp -> right)
                tmp = tmp -> right;
            else
                fl = false;
        if (el < tmp -> inf)
            tmp -> left = new Node(el);
        else
            tmp -> right = new Node(el);
    }
}

void Tree::LKP(Node *root){
    if (!root)
        return;
    LKP(root -> left);
    cout << root->inf <<" ";
    LKP(root -> right);
}

void Tree::LKP(){
    LKP(root);
}

void Tree::Clear(){
    Clear(root);
}

void Tree::Clear(Node *root){
    if (!root)
        return;
    Clear(root -> left);
    Clear(root -> right);
    delete root;
}

void Tree::Add(int el){
    Add(root, el);
}

void Tree::Add(Node *&root, int el){
    if (!root)
        root = new Node(el);
    else if (el < root -> inf)
        Add(root -> left, el);
    else
        Add(root -> right, el);
}

bool Tree::Find(int el){
    return Find(root, el);
}

bool Tree::Find(Node *root, int el){
    if (!root)
        return false;
    if (root -> inf == el)
        return true;
    if (el < root -> inf)
        return Find(root->left, el);
    return Find(root->right, el);
}


int main()
{
    Tree t;
    t.Add(5);
    t.Add(10);
    t.Add(3);
    t.Add(2);
    t.Add(7);
    t.Add(11);
    t.LKP();
    cout << t.Find(21);
//    cout << "Hello world!" << endl;
    return 0;
}
