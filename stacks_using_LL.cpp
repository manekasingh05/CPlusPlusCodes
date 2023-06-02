#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=nullptr;              //global pointer is needed to store values and used in multiple functions

void Push(int val)
{
    struct Node *t = new Node;

    if(t==nullptr)
    {
        cout<<"stackoverflow\n";
    }
    else{
    t->data=val;
    t->next=first;
    first=t;
    }
}

int pop()
{
    int x=-1;
    struct Node *t;
    if(first==nullptr)
    {
        cout<<"stack is empty\n";
    }
    else{
        t=first;
        first=first->next;
        x=t->data;
        delete t;
    }
    return x;
}

void Display()
{
    struct Node *p;
    p=first;
    while(p!=nullptr)
    {
        cout<<p->data;
        p=p->next;
    }
    cout<<endl;
}

int main()
{
    Push(10);
    Push(20);
    Push(30);
    Push(40);
    Push(50);
    Push(60);

    Display();

    pop();
    pop();

    Display();
    
return 0;
}