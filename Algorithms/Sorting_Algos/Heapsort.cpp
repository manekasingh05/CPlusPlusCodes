/* It can be done by deleting the first element from max heap and putting the last element into the first index of array and repeating
the steps again and again */

//Time Complexity: O(nlogn)

#include<iostream>
using namespace std;

void swap(int *arr, int i, int j)
{
    int temp;
    temp = i;
    i = j;
    j = temp;
}

void heapify(int *arr, int n)              //max heap created
{
    for(int i=(n/2)-1;i>=0;i--)
    {
       int j=2*i+1;
        while(j < n-1)
        {
            if(arr[j] < arr[j+1])
            {
                j=j+1;
            }
            if(arr[i] < arr[j])
            {
                swap(arr,i,j);
                i = j;
                j = 2*i+1;
            }else{
                break;
            }

        }
    }
    for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }
}

void heapsort(int *arr, int n)
{
    int temp,x;
     x=arr[1];
     arr[1]=arr[n];
     arr[n]=x;
    int i=1;
    int j=2*i;
    while(j <= n-1)
    {
        if(arr[j]<arr[j+1] && j<n-1)
        {
            j=j+1;
        }
        if(arr[i]<arr[j])
        {
            swap(arr,i,j);
            i=j;
            j=2*i;
        }else{
            break;
        }
    }
     for(int i=0;i<n;i++)
    {
        cout<<arr[i];
    }

}

int main()
{
    int n;
     cout<<"Enter the size:";
    cin>>n;
    int *arr = new int[n];

     for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    heapify(arr,n);

    for(int i=n - 1;i>1;i--)
    {
        heapsort(arr,i);
        cout<<endl;
    }
return 0;
}




