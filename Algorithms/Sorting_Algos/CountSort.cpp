//Sorting using 2 arrays


//Time Complexity:O(n)

#include<iostream>
using namespace std;

void CountSort(int *arrNum, int m)
{

    int i,max;

    max=arrNum[0];

    for(int i=1; i<m;i++)
    {
       if(max < arrNum[i])
       {
           max = arrNum[i];
       }
    }
    int *countarr = new int[max];

    int *output = new int[m];

    for(i = 0; i<m;i++)
    {
      ++countarr[arrNum[i]];
    }

    for(i=0;i<max;i++)
    {
        countarr[i] += countarr[i - 1]; 
    }

    for(i = 0; i<m; i++)
    {
       output[countarr[arrNum[i]] - 1] = arrNum[i];
       --countarr[arrNum[i]];
    }

    for(i=0;i<m;i++)
    {
        arrNum[i] = output[i];
    }

}


int main()
{
    int m;
    cin>>m;
int *arrNum = new int[m];


for(int i=0; i<m;i++)
{
    cin>>arrNum[i];
}

CountSort(arrNum,m);

for(int i=0;i<m;i++)
{
 cout<<arrNum[i];
}

delete[] arrNum;


return 0;
}

