#include<iostream>
#include<cmath>
using namespace std;

void Insert(int *arr, int val, int n)           //O(nlogn)
{
    int i = n;
    arr[n] = val;
    int temp = val;

    while(i > 0 && temp > arr[i%2==0 ? i/2 : (i-1)/2])
    {
       arr[i] = arr[i%2 == 0 ? i/2 : (i-1)/2];
        i = i%2==0 ? i/2 : (i-1)/2;
    }

  arr[i] = temp; 

  cout<<"Max heap will be :\n";

     for(int j=0;j<=n;j++)
    {
        cout<<arr[j]<<" ";
    }

}

//OR

/* void InsertUsingfloor(int *arr, int val, int n)   //cannot use
{
    int i = n + 1;
    arr[n + 1] = val;
    int temp = arr[n + 1];

    while(i > 0 && temp > arr[floor(i/2)])     // floor cannot be used with array subscript i.e, i, it should be integer
    {
       arr[i] = arr[floor(i/2)];
        i = floor(i/2);
    }

  arr[i] = temp; 
}   */



void Delete(int *arr, int n,int val)    // not applicable for deleting root element i.e first element
{
     int x,i,j,y=0,temp;
    for(int k=0; k<n;k++)                  //search and delete an element in heap O(n^2) - can apply binary search instead of linear for optimised soln the time complexity will be O(nlogn)
    {
        if(arr[k] == val)
        {
             y = val;
             arr[k] = arr[n - 1];                    // here we cannot delete any other element from heap so value of k and i will always be 1 i.e first index
             i = k;                                                // last index = n-1 where value is stored of an array, here value of i = k
             j = 2*i;
             x = arr[n - 1];
             arr[n - 1] = val;                      //deleted element brought back to last position

             while(j < n - 1)
             {
                 if(arr[j+1] > arr[j])
                 {
                     j=j+1;
                 }
                 if(arr[i] < arr[j])
                 {
                     temp = arr[i];
                     arr[i] = arr[j];
                     arr[j] = temp;
                     i=j;
                     j=2*j;
                 }
                 else{
                     break;
                 }
             }
        }
    }
    if(y == 0)
    {
        cout<<"Element not found!!!";
    }

      for(int p=0;p<n;p++)
    {
        cout<<arr[p]<<" ";
    }
    

}

int main()
{
    int n,val,val2;
    cout<<"Enter the size:";
    cin>>n;
    int *arr = new int[n];
    int *arr2 = new int[n];
    int *arr3 = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"Enter the value to insert in Max Heap!\n";
    cin>>val;

    Insert(arr,val,n);

    cout<<endl;


    cout<<"Create Heap by inserting one by one will be :\n";
   int j=0;
        while(j <= n)
    {
        cin>>val2;
        cout<<endl;
        arr2[j] = val2;
        Insert(arr2,val2,j);
        j++;
    }
   int x;
    cout<<"Enter element to delete!!";
    cin>>x;

      for(int j=0;j<n;j++)
    {
        cin>>arr3[j];
    }

    Delete(arr3,n,x);

 

    return 0;
}
