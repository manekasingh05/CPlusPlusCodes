#include<iostream>

using namespace std;

#define size 10
#define prime 7


int hashfun1(int key)
{
    int x;
    x = key%size;
    return x;
}

int hashfun2(int key)
{
    int x;
    x = key%prime;
    return prime - x;

}

int DoubleHashing(int *H, int key)
{
    int index;
    index = hashfun1(key);
    int i=0;
    while(H[(hashfun1(index) + i*hashfun2(index))%size]!=0)
    {
       i++;
    }
     return (index+i*hashfun2(index))%size;
}

void Insert(int H[], int key){
    int index = hashfun1(key);
 
    if (H[index] != 0){
        index = DoubleHashing(H, key);
    }
    H[index] = key;
}
 
int Search(int H[], int key){
    int index = hashfun1(key);
    int i = 0;
    while (H[(hashfun1(index) + i * hashfun2(index)) % size] != key){
        i++;
        if (H[(hashfun1(index) + i * hashfun2(index)) % size] == 0){
            return -1;
        }
    }
    return (hashfun1(index) + i * hashfun2(index)) % size;
}

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

    cout<<"Element found at :"<<temp;

   return 0;
}
 