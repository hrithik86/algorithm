//Merge k sorted arrays
/*
Given k sorted arrays of possibly different sizes, merge them and print the sorted output.

Examples:

Input: k = 3 
      arr[][] = { {1, 3},
                  {2, 4, 6},
                  {0, 9, 10, 11}} ;
Output: 0 1 2 3 4 6 9 10 11 

Input: k = 2
      arr[][] = { {1, 3, 20},
                  {2, 4, 6}} ;
Output: 1 2 3 4 6 20 
*/
#include <iostream>
#include <queue>
#include<functional>
#include<vector>
using namespace std;

// A pair of pairs, first element is going to 
// store value, second element index of array 
// and third element index in the array. 
typedef pair<int,pair<int,int>>ppi;         

vector<int> kMerge(vector<vector<int>>arr){
    vector<int> output;
    priority_queue<ppi,vector<ppi>,greater<ppi>>pq;
    for(int i=0;i<arr.size();i++){
        pq.push({arr[i][0],{i,0}});
    }
    while(!pq.empty()){
        ppi curr=pq.top();
        pq.pop();
        // i ==> Array Number 
        // j ==> Index in the array number  
        int i=curr.second.first;
        int j=curr.second.second;
        output.push_back(curr.first);
        if(j+1<arr[i].size()){
            pq.push({arr[i][j+1],{i,j+1}});
        }
    }
    return output;
}

int main()
{
    vector<int>v;
    vector<vector<int>>arr  {
                                {0,2,5,6},
                                {1,3,10,11},
                                {4,8,9}
                            };
    v=kMerge(arr);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    return 0;
}
