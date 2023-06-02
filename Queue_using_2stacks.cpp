#include<iostream>
using namespace std;

struct Stack1{
    int size1;
    int topPtr1;
    int *arr1;

};

struct Stack2{
    int size2;
    int topPtr2;
    int *arr2;
};


void create(struct Stack1 *s1, struct Stack2 *s2)
{
    cout<<"Enter size for stack1 and stack2:";
    cin>>s1->size1>>s2->size2;
    s1->topPtr1=s2->topPtr2=-1;
    s1->arr1 = new int[s1->size1];
    s2->arr2 = new int[s2->size2];
}

void Push(struct Stack1 *s1, int val)
{
     if(s1->topPtr1 == s1->size1 - 1)
    {
         cout<<"Queue overflow\n";
    }
    else{
        s1->topPtr1++;
        s1->arr1[s1->topPtr1] = val;
    }
}

void transfer(struct Stack1 *s1, struct Stack2 *s2)
{

    while(s2->topPtr2 != s2->size2 - 1 || s1->topPtr1 != -1)
    {
        s2->topPtr2++;
        s2->arr2[s2->topPtr2] = s1->arr1[s1->topPtr1];
        s1->topPtr1--;
    }

}

void enqueueUsingStack(struct Stack1 *s1, int val)
{

   Push(s1,val);

}

int pop(struct Stack2 *s2)
{
      int val=-1;
    if(s2->topPtr2 == -1)
    {
        cout<<"Queue underflow\n";
        return -1;
    }
    else{
       val = s2->arr2[s2->topPtr2];
       s2->topPtr2--;
    }

    return val;
}

int dequeueUsingStack(struct Stack1 *s1, struct Stack2 *s2)
{
    int x=-1;
    if(s2->topPtr2 == -1)
    {
        if(s1->topPtr1 == -1)
        {
            cout<<"Queue underflow!!!!";
            return x;
        }
        else{
            while(s1->topPtr1!=-1)
            {
                s2->topPtr2++;
                s2->arr2[s2->topPtr2] = s1->arr1[s1->topPtr1--];
                x = pop(s2);
                return x;
            }
        }
    }else{
        x = pop(s2);
        return x;
    }

}

void Display(struct Stack1 s1, struct Stack2 s2)
{
    cout<<"The stack 1 are:\n";
        for(int i=s1.topPtr1; i>=0; i--)
    {
       cout<<s1.arr1[i];
       cout<<endl;
    }

    cout<<"The stack 2 are:\n";

         for(int j=s2.topPtr2 ; j>=0; j--)
    {
       cout<<s2.arr2[j];
       cout<<endl;
    }
}


int main()
{
    struct Stack1 s1;
    struct Stack2 s2;

  
    create(&s1,&s2);

    enqueueUsingStack(&s1,10);
     enqueueUsingStack(&s1,20);
      enqueueUsingStack(&s1,30);
       enqueueUsingStack(&s1,40);

        cout<<endl;

       Display(s1,s2);

       transfer(&s1,&s2);

       cout<<endl;

       Display(s1,s2);

       cout<<endl;

    cout<<dequeueUsingStack(&s1,&s2);
    cout<<endl;

        Display(s1,s2);

        cout<<endl;

    return 0;
}