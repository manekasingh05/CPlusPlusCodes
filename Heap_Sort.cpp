// Abdul Bahri's correct method for both deleting and sorting

#include<iostream>
using namespace std;                     //correct method for delete and sort both and in every case

int HeapSort(int *arr, int n)             //heap sort is similar to delete function of max heap just adding deleted element from top at the end of heap in a loop
{
    int i,j,x,temp;
    x = arr[1];  
    arr[1] = arr[n];
    arr[n] = x;
    i = 1;
    j = i*2;
    while(j <= n - 1)
    {
       if(arr[j] < arr[j+1] && j < n-1)
       {
           j=j+1;
       }
       if(arr[i] < arr[j])
       {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i=j;
            j = 2*i;
       }
       else{
           break;
       }
    }

    return x;

}


int main()
{
    int n,*arr;
    cout<<"Enter size::\n";
    cin>>n;
    arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin>>arr[i];            //enter values in a max heap
    }

    for(int i=n - 1;i>1;i--)
    {
        HeapSort(arr,i);
        cout<<endl;
    }

    for(int i=1;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}