#include<iostream>
using namespace std;

struct Node{
    struct Node *prev;
    int data;
    struct Node *next;
}*first=nullptr;

void create(int *arr, int n)
{
   struct Node *t, *last;

   first = new Node;
   last = new Node;

   first->data = arr[0];
   first->next = first->prev = nullptr;
   last = first;

   for(int i=1;i<n;i++)
   {
       t = new Node;
       t->data = arr[i];
       t->next = last->next;
       t->prev = last;
       last->next = t;
       last=t;
   }

}

void Display(struct Node *p)
{
    while(p!=nullptr)
    {
        cout<<p->data;
        p=p->next;
    }
}

int length(struct Node *p)           //length of linked list
{
    int l=0;
    while(p!=nullptr)
    {
        l++;
        p=p->next;
    }
    return l;
}

void insert(struct Node *p)
{
     int index,element;
   cout<<"Enter the index";
   cin>>index;
   cout<<"Enter the element to insert";
   cin>>element;

   struct Node *t;
   if(index < 1 || index > length(first))
{
     cout<<"Enter index again";
     cin>>index;
}
if(index == 1)
{
   t = new Node;
   t->data = element;
   t->prev = nullptr;
   t->next = first;
   first->prev = t;
   first = t;
}
else{
    t = new Node;
    t->data = element;
    for(int i=0;i<index - 2;i++)
    {
        p=p->next;
    }
    t->prev = p;
    t->next = p->next;
    if(p->next!=nullptr)
    {
        p->next->prev = t;
    }
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
    if(index < 1 || index > length(first))
    {
        cout<<"Enter index again";
        cin>>index;
    }
    if(index == 1)
    {
         first=first->next;
         if(first!=nullptr)
         {
             first->prev = nullptr;
         }
         x=p->data;
         delete p;
    }
    else{
    for(int i=0;i<index-1;i++)
    {
      p=p->next;
    }
    p->prev->next = p->next;
    if(p->next!=nullptr)
    {
        p->next->prev= p->prev;
    }
    x=p->data;
    delete p;
    }
}

void Reverse(struct Node *p)           //Reversing DLL through swapping of pointers
{
    struct Node *temp;
   while(p!=nullptr)
   {
     temp = p->next;
     p->next = p->prev;
     p->prev = temp;
     p=p->prev;
     if(p->next == nullptr)
     {
         p->next = p->prev;
         p->prev = nullptr;
         first = p;
         break;
     }
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
    int Length = length(first);
    cout<<Length;
    insert(first);
    Display(first);
    cout<<endl;
    Delete(first);
    Display(first);
    cout<<endl;
    Reverse(first);
    Display(first);

    return 0;
}