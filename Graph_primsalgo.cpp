#include<iostream>
using namespace std;

#define I 32767


void Display(int t[2][6], int cost[8][8]){
 cout << "\nMinimum Spanning Tree Edges (w/ cost)\n" << endl;
    int sum = 0;
    for (int i=0; i<6; i++){
        int c = cost[t[0][i]][t[1][i]];
        cout << "[" << t[0][i] << "]---[" << t[1][i] << "] cost: " << c << endl;
        sum += c;
    }
    cout << endl;
    cout << "Total cost of MST: " << sum << endl;
}


void primsMST(int cost[8][8], int n)
{
    int u,v,min;
    min = I;
    int near[8];
    int t[2][6] = {0};                              //if V=8 then col = V-2

    for(int i=1;i<8;i++)
    {
        near[i]=0;
      for(int j=i;j<8;j++)
      {
           if(cost[i][j] < min)             //finding minimum element in upper triangular matrix because in lower element repeats itself
           {
              min = cost[i][j];
              u=i;
              v=j;
           }
      }
    }
    t[0][0] = u;
    t[1][0] = v;
    near[u] = near[v] = 0;

    for(int i=1;i<8;i++)
    {
        if(near[i]!=0)
        {
            if(cost[i][u] < cost[i][v])
            {
                near[i] = u;
            }else{
                near[i] = v;
            }
        }
    }
    for(int i=1;i<7;i++)
    {
        int k;
        min = I;
        for(int j=1;j<8;j++)
        {
            if(near[j]!=0 && cost[j][near[j]] < min){
                k=j;
                min = cost[j][near[j]];
            }

        }
        t[0][i] = k;
        t[1][i] = near[k];
        near[k] = 0;

        for(int j=1;j<8;j++)
        {
            if(near[j]!=0 && cost[j][k] < cost[j][near[j]]){
                near[j] = k;
            }
        }

    }

Display(t, cost);

}




int main()
{
    int cost [8][8] = {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };

    int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1;

     primsMST(cost,n);
 
 return 0;
}