#include<iostream>          //linear probing is another method to avoid collision in hashtable

using namespace std;

#define size 10

int hashfun(int key)
{
    int x;
    x = key%size;
    return x;

}

int Quadprobe(int *H, int key)
{
    int index = hashfun(key);
    int i=0;
    while(H[(index+i*i)%size]!=0)
    {
        i++;
    }
    return (index+i*i)%size;
}

void Insert(int *H, int key)
{
   int index;
   index = hashfun(key);

   if(H[index]!=0)
   {
       index = Quadprobe(H,key);
   }
  H[index] = key;

}

int Search(int *H, int key)
{
    for(int i=0;i<10;i++)
    {
        if(H[i] == key)
        {
            return key;
        }
    }
    return 0;

}

//OR


/*

index at which key is found 

int Search(int *H, int key)
{
    int index = hashfun(key);
    int i=0;
   while(H[(index + i)%sise]!=key)
   {
       i++;
   }

    return (index+i)%size;   

}

*/

int main()
{
    int *H = new int[10];
    int temp;

    for(int i=0; i<10;i++)
    {
        H[i] = 0;
    }

    Insert(H,12);
    Insert(H,22);
    Insert(H,42);
    Insert(H,48);
    Insert(H,52);


    for(int i=0; i<10;i++)
    {
        cout<<H[i]<<" ";
    }

    temp = Search(H,48);

    cout<<endl;

    cout<<"Element found is :"<<temp;

   return 0;

  
}