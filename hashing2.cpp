/*
Removing duplicate elements from array
Input : arr[] = { 1, 2, 5, 1, 7, 2, 4, 2}
Output : 1 2 5 7 4
Explanation : {1, 2} appear more than one time.
*/
#include <iostream>
#include<unordered_map>
using namespace std;

void remDuplicates(int a[],int n){
    int i;
    unordered_map<int,bool>um;  //key is the array element, value is either true or false 
                                //depending upon wheter it is visited or not
    
    for(i=0;i<n;i++){
        um[a[i]]=false;         //all are unvisited at first
    }
    for(i=0;i<n;i++){
        if(um[a[i]]==false){
            cout<<a[i]<<" ";
        }   
        um[a[i]]=true;          //making the element visited
    }
    return;
}

int main()
{
    int a[]={1, 2, 5, 1, 7, 2, 4, 2};
    int n=sizeof(a)/sizeof(a[0]);
    remDuplicates(a,n);
    return 0;
}
