#include<iostream>
using namespace std;
struct Node{
    int data;
    struct Node *next;
}*first=nullptr;

void create(int *arr, int n)
{
    struct Node *last = new Node;
    struct Node *temp;

    first = new Node;

    first->data = arr[0];
    first->next = first;              //Circular linked list first node created and points to itself
    last=first;

    for(int i=1;i<n;i++)
    {
        temp = new Node;
        temp->data = arr[i];
        temp->next = last->next;
        last->next = temp;
        last = temp;

    }
}

void Display(struct Node *p)
{
    do
    {
        cout<<p->data;
        p = p->next;
    }while(p!=first);
}

void RDisplay(struct Node *p)
{
    static int flag=0;
    if(p!=first || flag == 0)
    {
        flag=1;
        cout<<p->data;
        RDisplay(p->next);
    }
    flag=0;
}

int Length(struct Node *p)
{
    int l=0;
    do
    {
        l++;
        p = p->next;
    }while(p!=first);

    return l;
}

void Insert(struct Node *p)
{
   int index,element;
   cout<<"Enter the index";
   cin>>index;
   cout<<"Enter the element to insert";
   cin>>element;

   struct Node *t;

if(index < 1 || index > Length(first))
{
     cout<<"Enter index again";
     cin>>index;
}
if(index == 1)
{
    t = new Node;
    t->data = element;
    if(first == nullptr)             //first Node
    {
        first = t;
        t->next = first;
    }
    else{
        while(p!=first)               //last node
        {
            p=p->next;
        }
        p->next = t;
        t->next = first;
        first = t;
    }
}
else{
      t = new Node;
      t->data = element;
    for(int i=0;i<index - 2;i++)
    {
        p=p->next;
    }
    t->next = p->next;
    p->next = t;

}

}

void Delete(struct Node *p)
{
    struct Node *t = new Node;
    int x;
    int index;
    cout<<"Enter the index you want to delete";
    cin>>index;
    if(index < 1 || index > Length(first))
    {
        cout<<"Enter index again";
        cin>>index;
    }
    if(index == 1)
{
    while(p!=first)
    {
        p = p->next;
    }
    x = first->data;
    if(p == first)
    {
       delete first;
       first = nullptr;
    }
    else{
        p->next = first->next;
        delete first;
        first = p->next;
    }
}
else{
    for(int i=0;i<index-2;i++)
    {
      p=p->next;
    }
    t=p->next;
    p->next=t->next;
    x=t->data;
    delete t;
}
}


int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    create(arr,n);
    Display(first); 
    RDisplay(first);
    Insert(first);
    Display(first);
    Delete(first);
    Display(first);

    return 0;
}