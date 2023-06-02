/* A Naive recursive C++ program to find minimum number operations to convert str1 to str2

#include <bits/stdc++.h>
using namespace std;
 

int min(int x, int y, int z) { return min(min(x, y), z); }
 
int editDist(string str1, string str2, int m, int n)
{

    if (m == 0)
        return n;
 

    if (n == 0)
        return m;
 

    if (str1[m - 1] == str2[n - 1])
        return editDist(str1, str2, m - 1, n - 1);
 
    return 1
           + min(editDist(str1, str2, m, n - 1), // Insert
                 editDist(str1, str2, m - 1, n), // Remove
                 editDist(str1, str2, m - 1,
                          n - 1) // Replace
             );
}
 
int main()
{
    string str1 = "sunday";
    string str2 = "saturday";
 
    cout << editDist(str1, str2, str1.length(),
                     str2.length());
 
    return 0;
} */

//Time Complexity: O(m x n)


#include<iostream>
using namespace std;

int min(int x, int y, int z) 
{ 
    return min(min(x, y), z); 
}
 
int editDistDP(string str1, string str2, int m, int n)
{
    int dp[m + 1][n + 1];
 
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {

            if (i == 0)
            {
                dp[i][j] = j; 

            }else if(j == 0){
                dp[i][j] = i;

            }else if(str1[i - 1] == str2[j - 1]){
                dp[i][j] = dp[i - 1][j - 1];

            }else{
            dp[i][j] = 1 + min(dp[i][j - 1], // Insert
                            dp[i - 1][j], // Remove
                            dp[i - 1][j - 1]); // Replace
            }
        }
    }
    return dp[m][n];
}

int main()
{

    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDistDP(str1, str2, str1.length(), str2.length());
 
    return 0;
}