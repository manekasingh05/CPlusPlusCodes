//Time Complexity: O(N * N!)

#include<iostream>
using namespace std;

void swap(string x, string y)
{
    string temp;
    temp = x;
    x = y;
    y = temp;
}

void permute(string s, int l, int r)
{
    if(l==r)
    {
       cout<<s<<endl;
    }else{
        for(int i=l; i<=r; i++)
        {
            swap(s[l],s[i]);
            permute(s,l+1,r);
            swap(s[l],s[i]);             //backtracking
        }
    }
}

int main()
{
    string s;
    getline(cin,s);
    int l=0;
    int r=s.length();
    permute(s,l,r-1);
    return 0;
}