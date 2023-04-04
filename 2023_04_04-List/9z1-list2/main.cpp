#include <iostream>

using namespace std;

struct Node {
    int inf = 0;
    Node *prev = nullptr, *next = nullptr;
    Node(int z);
};

Node::Node(int z) {
    inf = z;
}

struct List {
    Node *head = nullptr, *tail = nullptr;
    int size = 0;

    List();
    ~List();

    void AddFirst(int z);
    void AddLast(int z);
    bool DelFirst();
    bool DelLast();
    void PrintFirstLast();
    void PrintLastFirst();
    void Clear();
    void Sort();
    bool Sort1();
};

List::List(){
    cout << "Hello" << '\n';
}

List::~List(){
    cout << "Bye" << '\n';
    Clear();
}

void List::AddFirst(int z) {
    Node *p = new Node(z);
    if (!head) // (head == nullptr)
        head = tail = p;
    else {
        p -> next = head;
        head -> prev = p;
        head = p;
    }
    ++size;
}

void List::AddLast(int z) {
    Node *p = new Node(z);
    if (!head) // (head == nullptr)
        head = tail = p;
    else {
        p -> prev = tail;
        tail -> next = p;
        tail = p;
    }
    ++size;
}

bool List::DelFirst() {
    if (!head) // (head == nullptr)
        return false;
    Node *p = head;
    head = head -> next;
    if (head)
        head->prev = nullptr;
    else
        tail = nullptr;
    delete p;
    --size;
    return true;
}

bool List::DelLast() {
    if (!tail) // (head == nullptr)
        return false;
    Node *p = tail;
    tail = tail -> prev;
    if (tail)
        tail->next = nullptr;
    else
        head = nullptr;
    delete p;
    --size;
    return true;
}

void List::PrintFirstLast() {
    Node *p = head;
    while (p) {
        cout << p->inf << ' ';
        p = p->next;
    }
    cout << '\n';
}

void List::PrintLastFirst() {
    Node *p = tail;
    while (p) {
        cout << p->inf << ' ';
        p = p->prev;
    }
    cout << '\n';
}

void List::Clear() {
    while(DelFirst());
}

bool List::Sort1() {
    bool res = false;
    Node *p = head;
    while(p->next) {
        if (p->inf > p->next->inf){
            res = true;
            swap(p->inf, p->next->inf);
        }
        p = p->next;
    }
    return res;
}

void List::Sort() {
    if (size < 2)
        return;
    bool flag = true;
    while(flag)
        flag = Sort1();
}

int main()
{
    List l1;
    l1.AddFirst(1);
    l1.AddFirst(24);
    l1.AddFirst(3);
    l1.AddLast(77);
    l1.AddLast(8);
    l1.AddLast(9);
    l1.Sort();
    l1.PrintFirstLast();
    l1.PrintLastFirst();

    cout << "Hello world!" << endl;
    return 0;
}
