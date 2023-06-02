// Constructing Binary tree using queue and stack for iterative traversals

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root=nullptr;

struct Queue{
    int size;
    Node **arr;
    int front;
    int rear;
};

struct Stack{
    int topPtr;
    int size;
    struct Node **arr;
};

void create(struct Queue *q)
{
    cout<<"Enter size of queue:\n";
    cin>>q->size;
    q->front=q->rear=-1;
    q->arr = new Node * [q->size];         
}

void enqueue(struct Queue *q, Node *val)
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


Node * dequeue(struct Queue *q)
{
    Node *x=nullptr;
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

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}

void Treecreate()
{
    struct Node *p,*t;
    int x;
    struct Queue q;
   create(&q);

   cout<<"Enter root value:\n";
   cin>>x;
   root = new Node;
   root->data=x;
   root->lchild=root->rchild=nullptr;
   enqueue(&q,root);

   while(!isEmpty(q))
   {
       p = dequeue(&q);
       cout<<"Enter left child value of:"<<p->data<<endl;
       cin>>x;
       if(x!=-1)
       {
           t = new Node;
           t->data = x;
           t->lchild=t->rchild=nullptr;
           p->lchild=t;
           enqueue(&q,t);
       }
       cout<<"Enter right child value of:"<<p->data<<endl;
       cin>>x;
       if(x!=-1)
       {
           t = new Node;
           t->data = x;
           t->lchild=t->rchild=nullptr;
           p->rchild=t;
           enqueue(&q,t);
       }
   }

}


void Stackcreate(struct Stack *st){
cout<<"Enter size";
cin>>st->size;
st->topPtr=-1;
st->arr = new Node * [st->size];
}


void Push(struct Stack *st, struct Node *val)
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


struct Node * Pop(struct Stack *st)
{
    struct Node *val=nullptr;
    if(st->topPtr == -1)
    {
        cout<<"Stack underflow\n";
        return nullptr;
    }
    else{
       val = st->arr[st->topPtr];
       st->topPtr--;
    }
    return val;
}

bool isEmpty(struct Stack st)
{
    if(st.topPtr == -1)
    {
        return 1;
    }
    return 0;
}


void Ipreorder(struct Node *p)
{
    struct Stack st;
    Stackcreate(&st);

    while(p!=nullptr || !isEmpty(st))
    {
        if(p!=nullptr)
        {
            cout<<p->data<<" ";
            Push(&st,p);
            p=p->lchild;
        }
        else{
            p=Pop(&st);
            p=p->rchild;
        }

    }
}

void Iinorder(struct Node *p)
{
    struct Stack st;
    Stackcreate(&st);

    while(p!=nullptr || !isEmpty(st))
    {
        if(p!=nullptr)
        {
            Push(&st,p);
            p=p->lchild;
        }
        else{
            p=Pop(&st);
            cout<<p->data<<" ";
            p=p->rchild;
        }

    }
}


int main()
{
     Treecreate();

    Ipreorder(root);

}