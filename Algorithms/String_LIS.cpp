// Function to find length of longest
// increasing subsequence in a string using dp
//Time Complexity: O(N)

#include<iostream>
using namespace std;

int lis(string s)
{
    int dp[30] = { 0 };
    int N = s.size();
    int lis = INT_MIN;

    for(int i=0 ;i<N; i++)
    {
        int val = s[i] - 'a';
        int curr=0;

        for(int j=0; j<val; j++)
        {
            curr = max(curr, dp[j]);
        }

        curr++;
        lis = max(lis,curr);
        dp[val] = max(dp[val],curr);
    }

    return lis;

}

int main()
{
    string s = "fdryutiaghfse";
    cout << lis(s);
 
    return 0;
}
