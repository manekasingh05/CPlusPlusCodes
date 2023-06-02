#include<iostream>
using namespace std;

struct Node {

    int data;
    struct Node *ptr;            //next pointer
}*first=nullptr,*second=nullptr,*third=nullptr;    //global pointer


void createLinkedList(int *arr, int n)
{
    struct Node *last = new Node;
    struct Node *temp;

    first = new Node;

    first->data=arr[0];         //creating first node
    first->ptr=nullptr;
    last=first;



for(int i=1;i<n;i++)
{
    temp = new Node;
    temp->data=arr[i];
    temp->ptr=nullptr;
    last->ptr=temp;
    last=temp;
}

}

void createLinkedList2(int *arr2, int m)
{
    struct Node *temp;
    struct Node *last = new Node;

    second = new Node;

    second->data=arr2[0];
    second->ptr=nullptr;
    last=second;

    for(int i=1;i<m;i++)
    {
        temp = new Node;
        temp->data=arr2[i];
        temp->ptr=nullptr;
        last->ptr=temp;
        last=temp;
    }
}

void Display(struct Node *p)        //displaying linked list
{
    while(p!=nullptr)
    {
        cout<<p->data<<" ";
        p=p->ptr;
    }
}

void RecursiveDisplay(struct Node *p)
{
if(p!=nullptr)
{
    cout<<p->data;
    RecursiveDisplay(p->ptr);
}
}

void RecursiveDisplayReverse(struct Node *p)      //Reverse printing element
{
if(p!=nullptr)
{
    RecursiveDisplay(p->ptr);
    cout<<p->data;
}
}


int lengthList(struct Node *p)           //length of linked list
{
    int l=0,sum=0;
    while(p!=nullptr)
    {
        l++;
        sum = sum + p->data;
        p=p->ptr;
    }
    cout<<endl<<sum<<endl;
    return l;
}

int MaxElement(struct Node *p)
{
    int max;

    max = p->data;
    while(p!=nullptr)
    {
        if(max < p->data)
        {
            max = p->data;
        }

        p = p->ptr;
    }
    return max;
}

int linearsearch(struct Node *p, int element)
{
    while(p!=nullptr)
    {
        if(element == p->data)
        {
            return element;
        }
        p=p->ptr;
    }
    return 0;
}

void insertNode(struct Node *p, int index)
{
   int newdata;
   struct Node *newNode = new Node;
   cout<<"Enter data in new node";
   cin>>newdata;
   newNode->data = newdata;
   if(index < 0 || index > lengthList(p))
   {
       cout<<"Enter index again";
       cin>>index;
   }
   if(index == 1)
   {
       newNode->ptr = first;
       first = newNode;
   }
   else{
       for(int i=0; i<index - 1;i++)
       {
         p=p->ptr;
       }
         newNode->ptr = p->ptr;
         p->ptr = newNode;

   }

}

void DeleteNode(struct Node *p)
{
    int x=-1;
    struct Node *t = new Node;
    cout<<"Enter index you want to delete";
    int index;
    cin>>index;
   if(index <= 0 || index > lengthList(p))
   {
       cout<<"Enter index again";
       cin>>index;
   }
   if(index == 1)
   {
       t=first;
       x=first->data;
       first=first->ptr;
       delete t;
   }
   else{
        for(int i=0; i<index - 1;i++)
       {
         t=p;
         p=p->ptr;
       }
       t->ptr=p->ptr;
       x=p->data;
       delete p;
   }

}

void RemoveDuplicates(struct Node *p)         //first we will sort linked list and then remove duplicates
{
    struct Node *q = new Node;
    q = p->ptr;

    while(q!=nullptr)
    {
        if(p->data == q->data)
        {
            p->ptr = q->ptr;
            delete q;
            q=p->ptr;
        }
        else{
            p=q;
            q=q->ptr;
        }
    }

   Display(first);
}


void Merge(struct Node *p,struct Node *q)
{
struct Node *last;
if(p->data < q->data)
{
    third=last=p;
    p=p->ptr;
   third->ptr=NULL;
}
else
{
third=last=q;
q=q->ptr;
third->ptr=NULL;
}
while(p && q)
{
if(p->data < q->data)
{
last->ptr=p;
last=p;
p=p->ptr;
last->ptr=NULL;
}
else
{
last->ptr=q;
last=q;
q=q->ptr;
last->ptr=NULL;
}
  if(p)last->ptr=p; 
  if(q)last->ptr=q;
 }
}


int main()
{
    int n,m;
    cin>>n>>m;
  int *arr = new int[n];
  int *arr2 = new int[m];

  for(int i=0;i<n;i++)
  {
      cin>>arr[i];
  }

   for(int j=0;j<m;j++)
  {
      cin>>arr2[j];
  }

    createLinkedList(arr,n);

    createLinkedList2(arr2,m);

  Display(first);

    RecursiveDisplay(first);

    RecursiveDisplayReverse(first);

    int k;

    k = lengthList(first);

    cout<<"length = \n"<<k;

    int max;

    max = MaxElement(first);

    cout<<"Maximum element in linked lis is: "<<max;

    int element;

    cout<<"Enter element:";

    cin>>element;

    if(linearsearch(first,element)!=0)
    {
        cout<<"Element found!!!!"<<linearsearch(first,element);
    }
    else{
        cout<<"No element found";
    }

    int index;
    cout<<"Insert node at-";
    cin>>index;

   insertNode(first,index);

   Display(first);

   DeleteNode(first);

   Display(first);

   cout<<endl;

   RemoveDuplicates(first);

   Merge(first,second);

   Display(third);

    return 0;
}