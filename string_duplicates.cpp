#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;


void Duplicate(vector<char> text)
{
    int k = 1;
    vector<char>::iterator itr;
    vector<char> text2;

   for(auto itr=text.begin(); itr!=text.end(); itr++)
   {
       if(*itr == *(itr + 1))
       {
           continue;
       }else{
           text2.push_back(*itr);
       }
   }
      for(int i=0; i<text.size(); i++)
   {
       cout<<text2[i];
   }
}

int main()
{

vector<char> text3(10);
for(int i=0; i < text3.size(); i++)
{
    cin>>text3[i];
}
sort(text3.begin(),text3.end());
Duplicate(text3);
    
}