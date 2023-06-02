#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int BinarySearch(vector<int> arr, int length, int element)
{

int i,j,temp;
int mid;
i = 0;
j= length - 1;


for(int i=0; i<length; i=i/2)
{
   mid = i%2==0 ? (i+j)/2: (i+1+j)/2;
   if(element == arr[mid])
   {
       temp = element;
       return temp;
   }
   else if(element < arr[mid])
   {
        j = mid - 1;

   }else{
       i = mid + 1;
   }

   if(temp == 0)
   {
       return 0;
   }
}



}

int main()
{
    int n,element,i;
    cout<<"Enter the values";
    cin>>n;
    cin>>element;
     vector<int> vec(n);

    for(i =0; i<n; i++)
    {
        cin>>vec[i];
    }

    sort(vec.begin(), vec.end());

    for(i =0; i<n; i++)
    {
        cout<<vec[i];
    }


cout<<endl;

   if(BinarySearch(vec,vec.size(),element) != 0)
   {
      cout<<"ELEMENT FOUND";
   }
   else{
       cout<<"Element not found";
   }

   return 0;

}