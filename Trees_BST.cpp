#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root=nullptr;

void Insert(struct Node *p, int key)
{
   struct Node *r, *t;
    if(root == nullptr)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = nullptr;
        root=t;
        return;
    }
    while (p!=nullptr)
    {
        r=p;
        if(key < p->data)
        {
           p=p->lchild;
        }else if(key > p->data)
        {
            p=p->rchild;
        }else{
            return;
        }
    }
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = nullptr;

        if(key < r->data)
        {
            r->lchild = t;
        }else{
            r->rchild = t;
        }

}

void Inorder(struct Node *p)                        //Inorder traversal gives sorted order result
{
    if(p!=nullptr)
    {
        Inorder(p->lchild);
        cout<<p->data<<" ";
        Inorder(p->rchild);
    }

}

struct Node * Search(struct Node *p, int key)
{
   while(p!=nullptr)
   {
       if(key == p->data)
       {
           return p;
       }else if(key < p->data)
       {
           p=p->lchild;
       }else
       {
           p = p->rchild;
       }
   }
   return nullptr;
}

int main()
{
    struct Node *temp;
    
    Insert(root,5);
    Insert(root,10);
    Insert(root,15);
    Insert(root,25);
    Insert(root,35);

    Inorder(root);

    cout<<endl;


     temp = Search(root,20);

     if(temp!=nullptr)
     {
         cout<<"Element found:"<<temp->data;
     }else{
         cout<<"Element not found!!!";
     }

    return 0;

}