//constructing Linked List using Stack

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=nullptr;


struct Stack{
    int size;
    int topPtr;
    int *arr;
};


void createStack(struct Stack *st)
{
    cout<<"Enter size:";
    cin>>st->size;
    st->topPtr = -1;
    st->arr = new int[st->size];
}

void Push(struct Stack *st, int val)
{
    if(st->topPtr == st->size-1)
    {
       cout<<"Stackoverflow\n";
    }
    else{
        st->topPtr++;
        st->arr[st->topPtr]=val;
    }
}

void create(struct Stack *st)
{
    struct Node *temp;

    struct Node *last = new Node;
    first = new Node;

    first->data = st->arr[st->topPtr];
    first->next = nullptr;
    last = first;

   for(int i=st->topPtr - 1;i>=0;i--)
    {
       temp = new Node;
       temp->data = st->arr[i];
       temp->next = nullptr;
       last->next = temp;
       last=temp;
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

void DisplayStack(struct Stack st)
{
   for(int i=st.topPtr;i>=0;i--)
   {
       cout<<st.arr[i];
   }
   cout<<endl;
}


int main()
{
struct Stack st;

createStack(&st);

Push(&st,10);
Push(&st,20);
Push(&st,30);
create(&st);

Display(first);

return 0;

}