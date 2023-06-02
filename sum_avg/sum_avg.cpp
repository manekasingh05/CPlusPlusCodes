#include<iostream>
using namespace std;
int main()
{
    int a,b,c,sum;
    float avg;
    cout<<"Enter three numbers:";
    cin>>a>>b>>c;
    sum=a+b+c;
    avg=sum/3;
    cout<<"sum=\n"<<sum<<endl<<"average=\n"<<avg;
    return 0;
}