#include<bits/c++.h>

using namespace std;

int miniDist(int distance[], bool Tset[]) // finding minimum distance
{
    int minimum=INT_MAX,ind;
              
    for(int k=0;k<6;k++) 
    {
        if(Tset[k]==false && distance[k]<=minimum)      
        {
            minimum=distance[k];
            ind=k;
        }
    }
    return ind;
}

void DijkstraAlgo(int graph[6][6],int src) // adjacency matrix 
{
    int distance[6]; // // array to calculate the minimum distance for each node                             
    bool Tset[6];// boolean array to mark visited and unvisited for each node
    
     
    for(int k = 0; k<6; k++)
    {
        distance[k] = INT_MAX;
        Tset[k] = false;    
    }
    
    distance[src] = 0;   // Source vertex distance is set 0               
    
    for(int k = 0; k<6; k++)                           
    {
        int m=miniDist(distance,Tset); 
        Tset[m]=true;
        for(int k = 0; k<6; k++)                  
        {
            // updating the distance of neighbouring vertex
            if(!Tset[k] && graph[m][k] && distance[m]!=INT_MAX && distance[m]+graph[m][k]<distance[k])
                distance[k]=distance[m]+graph[m][k];
        }
    }
    cout<<"Vertex\t\tDistance from source vertex"<<endl;
    for(int k = 0; k<6; k++)                      
    { 
        char str=65+k; 
        cout<<str<<"\t\t\t"<<distance[k]<<endl;
    }
}

int main()
{
    int choice;
    cout<<"--------------********----------------\n";
    cout<<"Is Polaris(North Star) visible to you?\n";
    cout<<"1. yes\n";
    cout<<"2. No\n";
    cout<<"-------------*********-------------------\n";
    cin>>choice;
    if(choice==1)
     {  
         int lat, lon;
    cout<<"Enter longitude and latitude of a polaris star(North Star).";
    cin>>lat>>lon;
    int n;
    cin>>n;
    int *graph = new int[n][n];
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<n; j++)
        {
            cin>>graph[i][j];
        }
    }
        DijkstraAlgo(graph,0);
     }
     else(choice==2)
     {
         cout<<"Enter nearest constellation which is visible!";
         cout<<"1. Little Dipper";
         cout<<"2. Big dipper";
         int choice2;
         cin>>choice2;
         if(choice2==1)
         {
                   int lat, lon;
                 cout<<"Enter longitude and latitude of Little dipper.\n";
                  cin>>lat>>lon;
         }
         else if(choice2==2)
         {
                      int lat, lon;
                 cout<<"Enter longitude and latitude of Big dipper.\n";
                  cin>>lat>>lon;
         }
         else{
             cout<<"Enter the correct choice."
         }
     }
     else{
         cout<<"Enter the correct choice!";
     }
    return 0;                           
}
