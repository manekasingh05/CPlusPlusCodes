#include<iostream>
using namespace std;               // in order to avoid collision in hash table chaining is used

struct Node{
    int data;
    struct Node *next;
};

void SortedInsert(struct Node **H, int x)                //array of pointers
{
    struct Node *t,*p=*H, *q=nullptr;

    t = new Node;
    t->data=x;
    t->next=nullptr;

    if(*H == nullptr)
    {
        *H=t;
    }else{
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        if(p==*H)
        {
            t->next=*H;
            *H=t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }
    }
}

struct Node *Search(struct Node *p, int key)
{
    while(p!=nullptr)
    {
        if(key == p->data)
        {
            return p;
        }
        p=p->next;
    }
    return nullptr;
}

//hashing

int hashfun(int key)     //hash function
{
    int x;

    x = key%10;
    return x;
}

void Insert(struct Node **H, int key)
{
    int index;
    index = hashfun(key);
    SortedInsert(&H[index],key);
   
}

int main()
{
    struct Node *H[10];
    struct Node *t;

    for(int i=0; i<10;i++)
    {
        H[i] = NULL;
    }

    Insert(H,12);
    Insert(H,22);
    Insert(H,42);

    t = Search(H[hashfun(22)],22);

    cout<<t->data;

    return 0;

}


