#include<iostream>
#include<string.h>
using namespace std;

void CountSortString(char *arr, int n)
{
int i;
char *outputarr = new char[n];
int *count = new int[255];


 for (i = 0; i<n; ++i)
 {
        ++count[arr[i]];
 }

 for(i=0;i<255;++i)
 {
     count[i] += count[i - 1];
 }

 for(i=0; i<n; ++i)
 {
     outputarr[count[arr[i]] - 1] = arr[i];
     --count[arr[i]];
 }

 for (i = 0; i<n; ++i)
 {
        arr[i] = outputarr[i];
 }

}

void CountSortNumber(int *arrNum, int m)
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
    int n,m;
    cin>>n>>m;
char *arr = new char[n];
int *arrNum = new int[m];

for(int i=0; i<n;i++)
{
    cin>>arr[i];
}

for(int i=0; i<m;i++)
{
    cin>>arrNum[i];
}

CountSortString(arr, n);

CountSortNumber(arrNum,m);


for(int i=0;i<m;i++)
{
 cout<<arr[i];
}


for(int i=0;i<m;i++)
{
 cout<<arrNum[i];
}


delete[] arr;
delete[] arrNum;


return 0;
}