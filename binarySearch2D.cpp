#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    bool binarySearch2d(vector<vector<int> >& matrix, int target) {

        int l=0;
        int h=matrix[0].size()-1;
        int mid;
        int r = matrix.size();

        for(int i=0; i<r;i++)
        {
            while(l<=h)
            {
                mid = l + (h-l)/2;
                if(matrix[i][mid] == target)
                {
                    return true;

                }else if(target < matrix[i][mid])
                {
                    h = mid - 1;

                }else if(target > matrix[i][mid])
                {
                    l = mid + 1;
                }

            }

        }

        return false;

    }
        
};

int main()
{
    Solution s;
 int n,m,element;
 cin>>n>>m>>element;

 vector<vector<int> > vec(n);
 vector<int> v1(m);

 for(int i=0;i<n;i++)
 {
     for(int j=0;j<m;j++)
     {
         cin>>v1[j];
     }
     vec.push_back(v1);
 }


 sort(vec[0].begin(), vec[0].end());


  for(int i=0;i<vec.size();i++)
 {
     for(int j=0;j<vec[0].size();j++)
     {
         cout<<vec[i][j]<<" ";
     }
     cout<<endl;
 }

bool ans = s.binarySearch2d(vec,element);


return 0;
}