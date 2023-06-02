#include<iostream>
#include<cstring>
using namespace std;

int countSubstring(string text)    //count number of substrings in a string
{
    int n = text.length();        //strlen is an inbuilt function from c so only used with char datatype also others like strcpy,strcat,strcmp etc
    return n*(n+1)/2;             // for string datatype use length() function
}

void comapreStrings(string text, string text2)
{
    int m = 0;
    int n = 0;
    for(int i=0,j=0; i<text.length(), j<text2.length(); i++,j++)
    {
        if(text[i]!= text2[j])
        {
           cout<<"Not equal";
           break;
        }
        else{
            m++;
            n++;
        }
    }
    if(m == text.length() && n == text2.length())
    {
        cout<<"Equal";
    }
}


int main()
{
string text,text2;
cout<<"Enter your string:";
getline(cin,text);
getline(cin,text2);
cout<<countSubstring(text);
comapreStrings(text,text2);

return 0;
}