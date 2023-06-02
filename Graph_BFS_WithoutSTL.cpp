// BFS without using STL

#include<iostream>                        //time complexity: O(n2)
using namespace std;

struct Queue {
    int size;
    int *arr;
    int front;
    int rear;
};

int create(struct Queue *q)
{
    cout<<"Enter size of queue which is equal to number of vertices:";
    cin>>q->size;
    q->front=q->rear=-1;
    q->arr = new int[q->size];

    return q->size;
}

void enqueue(struct Queue *q, int val)
{
    if(q->rear == q->size-1)
    {
        cout<<"queue is full";
    }
    else{
        q->rear++;
        q->arr[q->rear] = val;
    }
    
}

int dequeue(struct Queue *q)
{
    int x=-1;
    if(q->front == q->rear)
    {
        cout<<"Queue is empty!!";
    }
    else{
        q->front++;
        x = q->arr[q->front];
    }
    return x;
}

int isEmpty(struct Queue q)
{
    if(q.front == q.rear)
    {
         return 1;
    }
    return 0;
}

void Display(struct Queue q)
{
    for(int i=q.front+1;i<=q.rear;i++)
    {
        cout<<q.arr[i];
    }
    cout<<endl;
}

void BFS( struct Queue q, int vertex, int **arr, int n)
{
    int u,v;
    cout<<"Current vertex at which pointer is present is:\n"<<vertex<<" ";
    int *visited = new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    visited[vertex] = 1;
    enqueue(&q,vertex);
    while(isEmpty(q) == 0)
    {
      u = dequeue(&q);
      for(v=1;v<n;v++)
      {
          if(arr[u][v]==1 && visited[v]==0)
          {
              cout<<v<<" ";
              visited[v]=1;
              enqueue(&q,v);
          }
      }

    }
    cout<<endl;
}

int main()
{
    int n,vertex;
    struct Queue q;

   n = create(&q);

int **arr;
arr = new int * [n]; 

for (int i = 0; i < n; ++i) {                        //declaring 2d array
   
   arr[i] = new int[n];
}

cout<<"Enter elements in 2d array:\n";

for (int i = 0; i < n; ++i) {   // for each row

  for (int j = 0; j < n; ++j) { // for each column
    cin>>arr[i][j];
  }
}

cout<<"Enter vertex number";
cin>>vertex;

BFS(q,vertex,arr,n);

return 0;

}


