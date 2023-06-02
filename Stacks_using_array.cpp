#include<iostream>
using namespace std;


struct Stack{
    int topPtr;
    int size;
    int *arr;
};

void create(struct Stack *st){
cout<<"Enter size";
cin>>st->size;
st->topPtr=-1;
st->arr = new int[st->size];
}

void Display(struct Stack st)
{
    for(int i=st.topPtr; i>=0; i--)
    {
       cout<<st.arr[i];
       cout<<endl;
    }
}

void Push(struct Stack *st, int val)
{
    if(st->topPtr == st->size - 1)
    {
         cout<<"stackoverflow\n";
    }
    else{

        st->topPtr++;
        st->arr[st->topPtr] = val;
        
    }
}


int Pop(struct Stack *st)
{
    int val=-1;
    if(st->topPtr == -1)
    {
        cout<<"Stack underflow\n";
        return -1;
    }
    else{
       val = st->arr[st->topPtr];
       st->topPtr--;
    }
    return val;
}

int Peek(struct Stack st, int index)
{
    int x = -1;
   if(st.topPtr-index+1 < 0)
   {
       cout<<"Invalid index\n";
   }
   x = st.arr[st.topPtr-index+1];
   cout<<endl;
    
   return x;
}

bool isEmpty(struct Stack st)
{
    if(st.topPtr == -1)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Stack st)
{
    if(st.topPtr > -1)
    {
        return 1;
    }
    return 0;
}

int Stacktop(struct Stack st)
{
    if(!isEmpty(st))
    {
        return st.arr[st.topPtr];
    }
    return -1;
}


int main()
{
    struct Stack st;

create(&st);

Push(&st,10);
Push(&st,20);
Push(&st,30);
Push(&st,40);
cout<<"Pushed stack are:\n";
Display(st);
cout<<"popped value are:\n";
cout<<Pop(&st);
cout<<endl;
cout<<"popped stack are:\n";
Display(st);

cout<<"Stack value at given index is:\n";
cout<<Peek(st,1);
cout<<endl;

if(isEmpty(st))
{
    cout<<"Stack is empty!!!!";
}

if(isFull(st))
{
    cout<<"Stack is fulll!!!!";
}

cout<<endl;
cout<<"Top value at stack is:\n";
cout<<Stacktop(st);


return 0;

}

