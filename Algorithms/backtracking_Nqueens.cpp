/* Time Complexity: O(N!)
Uses Backtracking algorithm by keeping each queen at different columns and then checking rows, upper diagonal and lower diagonal one by one */
#include<iostream>
using namespace std;

#define N 4


void printarr(int board[N][N])
{
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(board[i][j])
            {
                cout<<"Q";
            }else{
                cout<<".";
            }
        }
        cout<<"\n";
    }

}

bool issafe(int board[N][N], int row, int col)
{
    int i,j;
 
    for(i=0;i<col;i++)           //for cols
    {
          if(board[row][i])
    {
       return false;
    }
    }

    for(i=row,j=col;i>=0 && j>=0;i--,j--)      //for upper diagonal
    {
        if(board[i][j])
        {
            return false;
        }
    }

    for(i=row,j=col; i<N && j>=0; i++,j--)       //for lower diagonal
    {
        if(board[i][j])
        {
            return false;
        }
    }

    return true;


}

bool solveNQUntil(int board[N][N], int col)
{
    if(col >=N)
    {
        return true;
    }

    for(int i=0; i<N; i++)
    {
       if(issafe(board, i, col))
       {
           board[i][col]=1;
           if(solveNQUntil(board,col+1))
           {
               return true;
           }
           board[i][col]=0;
       }
    }

    return false;
}


bool solveNQ()
{
    int board[N][N] = { { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 },
                        { 0, 0, 0, 0 } };
 
    if (solveNQUntil(board, 0) == false) {
        cout << "Solution does not exist";
        return false;
    }
 
    printarr(board);
    return true;
}



int main()
{
    solveNQ();
    return 0;

}