#include <iostream>

using namespace std;

struct Node {
    int inf = 0;
    Node *prev = nullptr, *next = nullptr;
};

struct List {
    Node *head = nullptr, *tail = nullptr;
    int size = 0;

    void AddFirst(int z);
    void AddLast(int z);
    bool DelFirst();
    bool DelLast();
    void PrintFirstLast();
    void PrintLastFirst();
    void Clear();
};

void List::AddFirst(int z){
    Node *p = new Node;
    p -> inf = z;
    if  (!head) //(head == nullptr)
        head = tail = p;
    else {
        p -> next = head;
        head -> prev  = p;
        head = p;
    }
    ++size;
}

void List::AddLast(int z){
    Node *p = new Node;
    p -> inf = z;
    if  (!head) //(head == nullptr)
        head = tail = p;
    else {
        p -> prev = tail;
        tail -> next  = p;
        tail = p;
    }
    ++size;
}

bool List::DelFirst(){
    if  (!head) //(head == nullptr)
        return false;

    Node *p = head;
    head = head -> next;
    if (head) // head != nullptr
        head -> prev = nullptr;
    else
        tail = nullptr;
    delete p;
    --size;
    return true;
}

bool List::DelLast(){
    if  (!tail) //(head == nullptr)
        return false;

    Node *p = tail;
    tail = tail -> prev;
    if (tail) // head != nullptr
        tail -> next = nullptr;
    else
        head = nullptr;
    delete p;
    --size;
    return true;
}

void List::PrintFirstLast(){
    Node *p = head;
    while (p) {
        cout << p->inf << " ";
        p = p -> next;
    }
    cout << '\n';
}

void List::PrintLastFirst(){
    Node *p = tail;
    while (p) {
        cout << p->inf << " ";
        p = p -> prev;
    }
    cout << '\n';
}

void List::Clear(){
    while (DelFirst());
}

int main()
{
    List l;
    l.AddFirst(1);
    l.AddFirst(2);
    l.AddFirst(3);
    l.AddLast(7);
    l.AddLast(8);
    l.AddLast(9);
    l.PrintFirstLast();
    l.PrintLastFirst();
    l.Clear();
    cout << "Hello world!" << endl;
    return 0;
}
