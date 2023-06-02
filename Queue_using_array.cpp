#include<iostream>
using namespace std;


struct Queue
{
    int size;
    int *arr;
    int front;
    int rear;
};

void create(struct Queue *q)
{
    cout<<"Enter size:";
    cin>>q->size;
    q->front=q->rear=-1;
    q->arr = new int[q->size];
}

void enqueue(struct Queue *q, int val)
{
    if(q->rear == q->size - 1)
    {
        cout<<"Queue is full!!!!";
    }
    else{
        q->rear++;
        q->arr[q->rear]=val;
    }
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front==q->rear)
    {
        cout<<"Queue is empty!!!";
    }
    else{
        q->front++;
        x = q->arr[q->front];
    }
    return x;
}

void Display(struct Queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        cout<<q.arr[i];
    }
    cout<<endl;
}

void DisplayCircularQueue(struct Queue q)
{
    int i=q.front+1;

    do{
        cout<<q.arr[i];
        i=(i+1)%q.size;

    }while(i!=(q.rear+1)%q.size);


    cout<<endl;

}



int main()
{
    struct Queue q;

    create(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    enqueue(&q,40);
    enqueue(&q,50);
    enqueue(&q,60);
    Display(q);

    cout<<endl;

    cout<<dequeue(&q);

    cout<<endl;

    Display(q);

    DisplayCircularQueue(q);


    return 0;
    
}
