/* Tree sort is a sorting algorithm that is based on Binary Search Tree data structure. 
It first creates a binary search tree from the elements of the input list or array and then performs 
an in-order traversal on the created binary search tree to get the elements in sorted order.*/

//Time Complexity: O(nlogn)

#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root=nullptr;

struct Queue{
    Node **arr;
    int rear;
    int front;
    int size;
};

void create(struct Queue *q)
{
    cout<<"Enter size of queue:\n";
    cin>>q->size;
    q->rear=q->front = 0;
    q->arr = new Node * [q->size];

}

void enqueue(struct Queue *q, Node *val)
{
    if(q->rear == q->size-1)
    {
        cout<<"Queue is fulll";
    }else
    {
        q->rear++;
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
        q->front++;
        x = q->arr[q->front];
    }
    return x;
}

int isempty(struct Queue q)
{
    return q.rear==q.front;
}
 
void Treecreate()                  //Creating tree using normal method of Queue and Node with double pointer array
{ 
   struct Node *p,*t;
   struct Queue q;
   int x;
   create(&q);

   cout<<"Enter root value\n";
   cin>>x;
   root = new Node;
   root->data = x;
   root->lchild=root->rchild=nullptr;
   enqueue(&q,root);

   while(!isempty(q))
   {
       p = dequeue(&q);
       cout<<"Enter the left child of:"<<p->data<<endl;
       cin>>x;
       if(x!=-1)
       {
           t = new Node;
           t->data = x;
           t->lchild=t->rchild=nullptr;
           p->lchild=t;
           enqueue(&q, t);
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


void Inorder(struct Node *p) {

    if(p!=nullptr){
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }

}

int main()
{
    Treecreate();

    Inorder(root);

}

