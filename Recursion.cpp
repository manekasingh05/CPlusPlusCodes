#include<iostream>
using namespace std;

int sum(int n)                   //sum of n natural numabers using recursion
{
    if(n > 0)
    {
         return n + sum(n - 1);
    }
    return 0;
}

int sumStatic(int n)                   //sum of n natural numabers using static variable
{
    static int x;
    if(n > 0)
    {
         x++;
         return sumStatic(n - 1) + x;      //returning time x value is fixed i.e, n
    }
    return 0;
}

void tree(int n)                   //tree recursion
{
    if(n > 0)
    {
         cout<<n;
         tree(n - 1);
         tree(n - 1);
    }
}

int factorial(int n)
{
    if(n > 0)
    {
        return n*factorial(n - 1);
    }
    if(n == 0)
    {
        return 1;
    }
}

int Power(int n, int power)
{
    if(power == 0)
    {
        return 1;
    }
    return Power(n, power - 1)*n;
}

int Powerxx(int n, int power)      //power recursion in less no of calls(optimised)
{
   if(power == 0)
   {
       return 1;
   }
   if(power%2 == 0)
   {
       return Powerxx(n*n,power/2);
   }
   return n*(n*n, (power - 1)/2);
}

double e(int x, int n)                  //taylor series
{
    static double p=1, k=1;
    double r;

    if(n==0)                
    {
        return 1;
    }
    r=e(x,n - 1);
    p=p*x;
    k=k*n;

    return r+p/k;
}

double e2(int x, int n)               //taylor using horner's rule optimised
{
   static double s;
   if(n == 0)
   {
       return s;
   }
   s = 1 + x*s/n;
   return e2(x, n - 1);
}

int fib(int n)
{
    if(n <= 1)
    {
        return n;
    }
    return fib(n - 2) + fib(n - 1);
}

void TOH(int n, int a, int b, int c)        //move from a to c(destination) using b
{
   if(n > 0)
   {
        TOH(n - 1,a,c,b);           //move a to b using c
        cout<<"("<<a<<","<<c<<")";
        TOH(n - 1, b,a,c);          //move b to c using a

   }
}


int main()
{

    int n,power,R,a,b,c;
    cin>>n;
    cin>>power;
    cout<<"SUM:"<<sum(n)<<endl;
    cout<<sumStatic(n)<<endl;
    tree(n);
    cout<<endl;
    cout<<"FACTORIAL:"<<factorial(n)<<endl;
    R = Power(n,power);
    cout<<"POWER:"<<R<<endl;
     cout<<"Optimised code for POWER:"<<Powerxx(n,power)<<endl;
     cout<<e(power,n)<<endl;
     cout<<fib(n);
     cin>>a>>n>>c;
     TOH(n,a,b,c);

    return 0;
}