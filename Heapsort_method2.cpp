// Error in sorting  (just trial but not succeeded)

#include<iostream>
using namespace std;
void HeapSort(int *arr, int n)             //heap sort is similar to delete function of max heap just adding deleted element from top at the end of heap in a loop
{                                         //sorting error
    int i,j,x,temp;
    x = arr[0];
    arr[0] = arr[n - 1];
    arr[n - 1] = x;
    i = 0;
    j = i*2 + 1;                     // for j not equal to 0 at index 0 (similar to heapify)
    while(j < n - 1)
    {
       if(arr[j] < arr[j+1] && j < n - 1)
       {
           j=j+1;
       }
       if(arr[i] < arr[j])
       {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i=j;
            j = 2*i + 1;
       }
       else{
           break;
       }
    }


}


int main()
{
    int n,*arr;
    cout<<"Enter size::\n";
    cin>>n;
    arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    for(int i=n;i>1;i--)
    {
        HeapSort(arr,i);
        cout<<endl;
    }

    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}