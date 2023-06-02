//Graph BFS and DFS using Queue made through linked list

#include<iostream>

using namespace std;

struct Node{
    int data;
    struct Node *next;
}*front=nullptr,*rear=nullptr;

void enqueue(int val)
{
    struct Node *t = new Node;
    if(t==nullptr)
    {
        cout<<"Queue is full";
    }
    else{
        t->data = val;
        t->next=nullptr;
        if(front==nullptr)
        {
            front=rear=t;
        }
        else{
            rear->next=t;
            rear=t;
        }
    }

}

int dequeue()
{
    int x=-1;
    struct Node *t;
    if(front==nullptr)
    {
        cout<<"Queue is empty!!!";
    }
    else{
        x = front->data;
        t=front;
        front=front->next;
        delete t;
    }
    return x;
}

int isEmpty()
{
 return front==NULL;
}

void BFS(int vertex, int arr[][7], int n)
{
    int u,v;
    cout<<"Current vertex at which pointer is present is:\n"<<vertex<<" ";
    int *visited = new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    visited[vertex] = 1;
    enqueue(vertex);
    while(!isEmpty())
    {
      u = dequeue();
      for(v=1;v<n;v++)
      {
          if(arr[u][v]==1 && visited[v]==0)
          {
              cout<<v<<" ";
              visited[v]=1;
              enqueue(v);
          }
      }

    }
    cout<<endl;
}

void DFS(int vertex,int arr[][7],int n)              //DFS is a recursive function
{
    static int *visited;
    visited = new int[n];

    if(visited[vertex] == 0)
    {
        cout<<vertex<<" ";
        visited[vertex]=1;
        for(int v=1;v<n;v++)
        {
            if(arr[vertex][v]==1 && visited[v] == 0)
            {
                DFS(v,arr,n);
            }

        }

    }
    

}

int main()
{
 int arr[7][7]={{0,0,0,0,0,0,0},
 {0,0,1,1,0,0,0},
 {0,1,0,0,1,0,0},
 {0,1,0,0,1,0,0},
 {0,0,1,1,0,1,1},
 {0,0,0,0,1,0,0},
 {0,0,0,0,1,0,0}};

 BFS(4,arr,7);

 DFS(4,arr,7);


 return 0;
}

