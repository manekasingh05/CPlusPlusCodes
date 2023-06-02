#include<iostream>
#include<iterator>
#include<algorithm>
#include<array>
#include<queue>
#include<list>
#include<vector>
#include<deque>
#include<map>


using namespace std;

int main() {

    int n;

vector<int> vec(6);
vector<int> v(6);

array<int,10> arr;

list<int> lis(6);

deque<int> deq;

vector<int>::iterator p;
vector<int>::iterator itr;

list<int>::iterator k;

deque<int>::iterator d;

map<int,int> keys;

priority_queue <int, vector<int>, greater<int> > g;          //priority queue as min heap

priority_queue <int, vector<int>, greater<int> > gq = g;


vector<vector<int> > v1;
vector<int> v2;

for(int i=0; i<5; i++)
{
    for(int j=0; j<5; j++)
    {
       cin>>v2[j];
    }
    v1.push_back(v2);
}

 for (int i = 0; i < v1.size(); i++) {
        for (int j = 0; j < v1[i].size(); j++)
            cout << v1[i][j] << " ";
        cout << endl;
    }



for(int i=0; i<vec.size(); i++)
{
cin>>vec[i];
}

int m;
for(int i=0; i<6; i++)
{
    cin>>m;
    keys.insert(pair<int, int>(i, m));

}

    map<int, int>::iterator itx;
    cout << "\nThe map keys is : \n";
    cout << "\tKEY\tELEMENT\n";
    for (itx = keys.begin(); itx != keys.end(); ++itx) {
        cout<<itx->first<<itx->second;
    }

    cout << endl;

for(int i=0; i<lis.size(); i++)
{
lis.push_back(i);
}

for(int i=0; i<arr.size(); i++)
{
cin>>arr[i];
}

vec.insert(vec.end(),7);

sort(vec.begin(), vec.end());

for(int i=0; i<vec.size(); i++)
{
cout<<vec[i];
}

for(int i=0; i<vec.size(); i++)
{
cout<<arr[i];
}


if(binary_search(vec.begin(),vec.end(),4))
{
    cout<<"Element found";
}
else{
    cout<<"Element not found";
}


cout<<endl;

reverse(vec.begin(),vec.end());

reverse(lis.begin(),lis.end());

lis.sort();
lis.reverse();


for(int i=0; i<lis.size(); i++)
{
    cin>>n;
    lis.push_back(n);
}


for(k = lis.begin(); k != lis.end(); k++)
{
 cout<<*k;

}



for(int i=0; i<vec.size(); i++)
{
cout<<vec[i];
}

cout<<endl;

for(auto p = vec.rbegin(); p != vec.rend(); p++)
{
cout<<*p;
}


cout<<endl;

itr = vec.begin() + 3;

d = deq.begin() + 4;

vec.erase(itr);

deq.erase(d);




for(int i=0; i<vec.size(); i++)
{
cout<<vec[i];
}



    return 0;
}