#include<iostream>
using namespace std;

struct Node{
    char data;
    struct Node *next;
}*first=nullptr;              //global pointer is needed to store values and used in multiple functions

void Push(char val)
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

char pop()
{
    char x=-1;
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

int pre(char x)              // To check precedence before infix to postfix conversion
{
    if(x=='+' || x=='-')
    {
        return 1;
    }
    else if(x == '*' || x == '/')
    {
        return 2;
    }
    else{
      return 0;
    }
}


int isOperand(char x)             // To check operand before infix to postfix conversion
{
     if(x=='+' || x=='-' || x=='*' || x=='/')
     {
         return 0;
     }
     else{
         return 1;
     }
}

char *IntoPos(char *infix)
{
    int i=0,j=0;
     int len = strlen(infix);
     char *postfix = new char[len + 2];
     while(infix[i]!= '\0')
     {

      if(isOperand(infix[i]))
      {
          postfix[j] = infix[i];
          i++;
          j++;
      }

      else{
          if(pre(infix[i]) > pre(first->data))
          {
              Push(infix[i]);
              i++;
          }
          else{
              postfix[j] = pop();
              j++;
          }
      }
     }
     while(first!=nullptr)
     {
         postfix[j] = pop();
         j++;
     }
     postfix[j] = '\0';
     return postfix;
}


int main()
{

    char *infix = "a+b*c";
    Push('#');                            // push any char in order to initialise somnething in first->data so we can compare
    char *postfix;

    postfix = IntoPos(infix);
    cout<<postfix;
    
    
return 0;
}