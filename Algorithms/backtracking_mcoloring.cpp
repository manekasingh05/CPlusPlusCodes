/* Time Complexity: O(m^V) */
#include<iostream>
using namespace std;

#define V 4

void printarr(bool graph[V][V], int color[])
{
    cout << "Solution Exists:"
            " Following are the assigned colors \n";
    for(int i=0; i<V;i++)
    {
        cout<<color[i];
    }
    cout<<"\n";
}

bool issafe(bool graph[V][V], int color[])
{
    for(int i=0; i<V;i++)
    {
        for(int j=i+1;j<V;j++)
        {
            if(graph[i][j] && color[i] == color[j])
            {
                return false;
            }
        }
    }
    return true;
}

bool graphcoloring(bool graph[V][V], int m, int color[V], int i)
{
    if(i == V)
    {
       if(issafe(graph,color))
       {
           printarr(graph,color);
           return true;
       }
       return false;
    }

    for(int j=1; j<=m; j++)
    {
      color[i]=j;
      if(graphcoloring(graph,m,color,i+1))
      {
          return true;
      }
      color[i]=0;
    }

    return false;
}

int main()
{
    bool graph[V][V] = {
        { 0, 1, 1, 1 },
        { 1, 0, 1, 0 },
        { 1, 1, 0, 1 },
        { 1, 0, 1, 0 },
    };
    int m =3;
    int color[V];
    for(int i=0;i<V;i++)
    {
        color[i]=0;
    }

    if (!graphcoloring(graph, m, color,0))
        cout << "Solution does not exist";
 
    return 0;

}