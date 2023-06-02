#include<iostream>
#include<queue>
#include<algorithm>
#include<iterator>

using namespace std;

struct Node{
    int data;
    struct Node *lchild;
    struct Node *rchild;
}*root=nullptr;

void Treecreate()
{
    struct Node *p,*t;
    queue<Node *> q;
    int x;
    cout<<"Enter the root value:\n";
    cin>>x;
    root = new Node;
    root->data=x;
    root->lchild=root->rchild=nullptr;
    q.push(root);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        cout<<"Enter the value of left child of:"<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild=t->rchild=nullptr;
            p->lchild=t;
            q.push(t);
        }
        cout<<"Enter the value of right child of:"<<p->data<<endl;
        cin>>x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild=t->rchild=nullptr;
            p->rchild=t;
            q.push(t);
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
