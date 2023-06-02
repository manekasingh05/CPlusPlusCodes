#include<iostream>
using namespace std;

struct Queue{
    int size;
    int *arr;
    int front;
    int rear;
};

void create(struct Queue *q)                    //with double ended queue front and rear both can operate insertion and deletion
{
    cout<<"Enter size:";
    cin>>q->size;
    q->front=q->rear=-1;
    q->arr = new int[q->size];
}

void enqueueUsingFront(struct Queue *q,int val)
{
    if(q->front == -1)
    {
        cout<<"DEQueue is overflow!!";
    }else{
        q->arr[q->front]=val;
        q->front--;
    }

}

void enqueueUsingRear(struct Queue *q,int val)
{
     if(q->rear == q->size-1)
     {
         cout<<"DEQueue overflow!!";
     }else{
         q->rear++;
         q->arr[q->rear]=val;
     }
}

int dequeueUsingFront(struct Queue *q)
{
    int x=-1;
    if(q->front == q->rear)
    {
        cout<<"DEQueue underflow!!!";
    }
    else{
        q->front++;
        x = q->arr[q->front];
    }
    return x;
}

int dequeueUsingRear(struct Queue *q)
{
    int x=-1;
    if(q->rear == -1)
    {
        cout<<"DEQueue underflow!!!!";
    }else{
        x = q->arr[q->rear];
        q->rear--;
    }
    return x;
}

void Display(struct Queue q)
{
    for(int i=q.front + 1;i<=q.rear;i++)
    {
        cout<<q.arr[i];
    }
    cout<<endl;
}

int main()
{
    struct Queue q;

     create(&q);
    enqueueUsingRear(&q,10);
    enqueueUsingRear(&q,20);
    enqueueUsingRear(&q,30);
    enqueueUsingRear(&q,40);
    enqueueUsingRear(&q,50);
    enqueueUsingFront(&q,60);
    Display(q);

    cout<<endl;

    cout<<dequeueUsingFront(&q);

    enqueueUsingFront(&q,100);

    cout<<dequeueUsingRear(&q);

    cout<<endl;

    Display(q);

    

return 0;

}