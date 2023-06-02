#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*front=nullptr,*rear=nullptr;


void enqueue(int val)
{
    struct Node *t = new Node;
    if(t==nullptr)
    {
        cout<<"Queue is full";
    }
    else{
        t->data = val;
        t->next=nullptr;
        if(front==nullptr)
        {
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }

}

int dequeue()
{
    int x=-1;
    struct Node *t;
    if(front==nullptr)
    {
        cout<<"Queue is empty!!!";
    }
    else{
        x = front->data;
        t=front;
        front=front->next;
        delete t;
    }
    return x;
}

void Display()
{
    struct Node *p = front;
    while(p!=nullptr)
    {
        cout<<p->data;
        p=p->next;
    }
    cout<<endl;
}


int main()
{

enqueue(10);
enqueue(20);
enqueue(30);
enqueue(40);
enqueue(50);
Display();

cout<<dequeue();

return 0;
}