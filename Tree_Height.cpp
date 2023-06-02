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

void create(struct Queue *q)
{
    cout<<"Enter size of queue:\n";
    cin>>q->size;
    q->front=q->rear=0;
    q->arr = new Node * [q->size];         
}

void enqueue(struct Queue *q, Node *val)
{
   if((q->rear+1)%q->size == q->front)
   {
       cout<<"Queue is full!!!";
   }
   else{
        q->rear=(q->rear+1)%q->size;
        q->arr[q->rear] = val;
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
        q->front = (q->front+1)%q->size;
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

void preorder(struct Node *p)                     //To display tree in preorder form recursive approach
{                                                 //Time - O(n)
   if(p!=nullptr)
   {
       cout<<p->data<<" ";
       preorder(p->lchild);
       preorder(p->rchild);
   }
}

int count(struct Node *p)
{
    int x=0,y=0;
    if(p!=nullptr)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        return x+y+1;
    }
    return 0;
}

int height(struct Node *p)
{
    int x=0,y=0;
    if(p == 0)
    {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);

    if(x>y)
    {
        return x+1;
    }else{
        return y+1;
    }
}

int CountLeafNodes(struct Node *p)            //to count number of non leaf nodes
{
    int x=0,y=0;
    if(p!=nullptr)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        if(p->lchild == nullptr && p->rchild == nullptr)
        {
            return x+y+1;
        }else{
            return x+y;
        }
        return 0;
    }
}

int CountNonLeafNodes(struct Node *p)            //to count number of non leaf nodes
{
    int x=0,y=0;
    if(p!=nullptr)
    {
        x = count(p->lchild);
        y = count(p->rchild);
        if(p->lchild!= nullptr && p->rchild!= nullptr)
        {
            return x+y+1;
        }else{
            return x+y;
        }
        return 0;
    }
}

int main()
{
    Treecreate();

    cout<<count(root)<<endl;
    cout<<height(root);
    cout<<CountLeafNodes(root)<<endl;
    cout<<CountNonLeafNodes(root)<<endl;

}