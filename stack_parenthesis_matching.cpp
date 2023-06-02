#include<iostream>
using namespace std;

struct Node{
    char data;
    struct Node *next;
}*first=nullptr;               //first=top

void push(char val)
{
    struct Node *t = new Node;
    if(t==nullptr)
    {
        cout<<"stack overflow";
    }
    else{
        t->data=val;
        t->next=first;
        first=t;
    }
}

char pop()
{
    char x=-1;
    struct Node *t;
    if(first==nullptr)
    {
    cout<<"stack is empty";
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

int isBalanced(char *exp)                                  //parenthesis matching
{
    for(int i=0; exp[i]!='\0';i++)
    {
        if(exp[i]=='(')
        {
            push(exp[i]);
        }
        else if(exp[i]=='{')
        {
            push(exp[i]);
        }
        else if(exp[i]=='[')
        {
            push(exp[i]);
        }
        else if(exp[i]==')')
        {
            if(first==nullptr)
            {
                return 0;
            }
            pop();
        }
           else if(exp[i]=='}')
        {
            if(first==nullptr)
            {
                return 0;
            }
            pop();
        }
               else if(exp[i]==']')
        {
            if(first==nullptr)
            {
                return 0;
            }
            pop();
        }
    }
    if(first==nullptr)
    {
        return 1;
    }
    else{
        return 0;
    }
}




int main()
{
    int n;
    cout<<"enter value of n";
    cin>>n;
    char *exp = new char[n];
    cout<<"enter brackets:";
    for(int i=0;i<n;i++)
    {
        cin>>exp[i];
    }
    cout<<isBalanced(exp);

    return 0;
}