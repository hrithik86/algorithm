//Activity Selection Problem
//Greedy Algo-1
#include <bits/stdc++.h>
using namespace std;

struct Activity 
{     
    int start, finish; 
};

bool actCompare(Activity a1,Activity a2){
    return a1.finish<a2.finish;
}

void printMaxActivities(Activity arr[],int n){
    sort(arr,arr+n,actCompare);
    cout << "Following activities are selected \n"; 
    cout<<"("<<arr[0].start<<","<<arr[0].finish<<"),";
    int i,j=0;
    for(i=1;i<n;i++){
        if(arr[i].start>=arr[j].finish){
            cout<<"("<<arr[i].start<<","<<arr[i].finish<<"),";
            j=i;
        }
    }
    
}

int main()
{
    Activity arr[]={{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}};
    int n = sizeof(arr)/sizeof(arr[0]); 
    printMaxActivities(arr, n);  
    
    return 0;
}
