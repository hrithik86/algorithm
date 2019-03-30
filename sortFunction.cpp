#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int a,int b){
    return a<b;
}
bool compareDesc(int a,int b){
    return a>b;
}

int main()
{
    int a[]={1,9,7,5,2};
    sort(a,a+5,compare);
    for(int i=0;i<5;i++)
    cout<<a[i]<<" ";
    cout<<"\nSorting in Descending order:\n";
    sort(a,a+5,compareDesc);
    for(int i=0;i<5;i++)
    cout<<a[i]<<" ";
    return 0;
}