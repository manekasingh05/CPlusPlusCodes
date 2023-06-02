/* 1.Binary Search
   2. Find min and max element
   3. Merge sort
   4. Quick sort
   5. Strassen matrix multiplication */

   #include<iostream>
   #include<vector>
   #include<algorithm>
   using namespace std;

   vector<int> binarysearchin2d(vector<vector<int> > vec, int element)
   {
        int row=0;
        int col = vec[row].size()-1;
        vector<int> ans;
        vector<int> noans;

        noans.push_back(-1);


        while(row < vec.size() && col >=0)
        {
            if(element == vec[row][col])
            {
                ans.push_back(row);
                ans.push_back(col);
                return ans;
            }
            else if(element > vec[row][col])
            {
                row++;
            }else{
                col--;
            }

           
        }

    return noans;
   }



   

   int main()
   {
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

    vector<int> ans = binarysearchin2d(vec,element);

 cout << "Element found at index: [";
    for (int i = 0; i < ans.size(); i++) {
        if (i == ans.size() - 1)
            cout << ans[i];
        else
            cout << ans[i] << ", ";
    }
    cout << "]";
    return 0;

   }