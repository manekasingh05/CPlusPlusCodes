/* Dynamic Programming solution to construct Longest
   Increasing Subsequence */
#include <iostream>
#include <vector>
#include<algorithm>
#include<iterator>
using namespace std;
 
void printLIS(vector<int> & arr)
{                                //or int x;
    for (int x : arr)            //or for(int i=0; i<n; i++)
        cout << x << " ";        //or x=arr[i];
    cout << endl;
}

void constructPrintLIS(int arr[], int n)
{

    vector<vector<int> > L(n);

    L[0].push_back(arr[0]);
 
    for (int i = 1; i < n; i++)
    {

        for (int j = 0; j < i; j++)
        {
     
            if ((arr[i] > arr[j]) &&
                    (L[i].size() < L[j].size() + 1))
                L[i] = L[j];
        }

        L[i].push_back(arr[i]);

    
    }

  vector<int> max = L[0];

  vector<int> x;
 
    for (int i=1; i<n; i++)
    {
        x = L[i];
         if (x.size() > max.size())
            max = x;

    }
 
    printLIS(max);
}
 
int main()
{
    int arr[] = { 3, 2, 6, 4, 5, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);

    constructPrintLIS(arr, n);
 
    return 0;
}
