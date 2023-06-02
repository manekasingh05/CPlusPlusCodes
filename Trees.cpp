//Creating Binary Tree using circular queue which uses array(double pointer) and display using different traversals
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

void postorder(struct Node *p) {

    if(p!=nullptr){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }

}

void Inorder(struct Node *p) {                       //Inorder gives sorted order result

    if(p!=nullptr){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }

}

void Levelorder(struct Node *p)
{
    struct Queue q;
    create(&q);

    cout<<p->data;
    enqueue(&q,p);
    while(!isEmpty(q))
    {
      p=dequeue(&q);
      if(p->lchild)
      {
         cout<<p->lchild->data;
         enqueue(&q,p->lchild);
      }
       if(p->rchild)
      {
         cout<<p->rchild->data;
         enqueue(&q,p->rchild);
      }
    }
}

int main()
{
    Treecreate();

    preorder(root);

    cout<<endl;

    postorder(root);

    cout<<endl;

    Inorder(root);

    cout<<endl;

    Levelorder(root);


}