//Rat in a maze

//create nxn matrix

//Time Complexity:O(2^(n^2))

#include<iostream>
using namespace std;


#define N 4

void printarr(int sol[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            cout<<sol[i][j];
        }
        cout<<"\n";
    }
}

bool issafe(int maze[N][N], int x, int y)
{
    if(x>=0 && x< N && y>=0 && y<N && maze[x][y]==1)
    {
        return true;
    }
    return false;
}

bool SolveMazeUntil(int maze[N][N], int x, int y, int sol[N][N])
{
    if(x == N -1 && y == N-1 && maze[x][y] == 1)
    {
        sol[x][y] = 1;
        return true;
    }
    if(issafe(maze,x,y) == 1)
    {
        if(sol[x][y] == 1)
        {
            return false;
        }

        sol[x][y] = 1;

        if(SolveMazeUntil(maze,x+1,y,sol) == true)
        {
            return true;
        }

        if(SolveMazeUntil(maze,x,y+1,sol) == true)
        {
            return true;
        }
        sol[x][y]=0;
        return false;
    }
return false;

}


bool SolveMaze(int maze[N][N])
{
int sol[N][N] = { { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 },
                      { 0, 0, 0, 0 } };
if(SolveMazeUntil(maze, 0, 0, sol) == false)
{
   return false;
}

printarr(sol);
return true;

}



int main()
{
     int maze[N][N] = { { 1, 0, 0, 0 },
                       { 1, 1, 0, 1 },
                       { 0, 1, 0, 0 },
                       { 1, 1, 1, 1 } };

SolveMaze(maze);



return 0;

}

