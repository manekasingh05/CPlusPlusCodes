#include<iostream>
#include<queue>
#include<algorithm>

using namespace std;

void BFS(int vertex, int arr[][8], int n)
{
    int u,v;
    int *visited = new int[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    cout<<vertex<<" ";
    visited[vertex] = 1;
    queue<int> q;
    q.push(vertex);

    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(v=1;v<n;v++)
        {
            if (arr[u][v] == 1 && visited[v] == 0){
                cout << v << " ";
                visited[v] = 1;
                q.push(v);
        }
    }

    }
    cout<<endl;
}

int main (){
 
    int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " ;
    BFS(1, A, 8);
 
    cout << "Vertex: 4 -> ";
    BFS(4, A, 8);
 
 
    return 0;
}