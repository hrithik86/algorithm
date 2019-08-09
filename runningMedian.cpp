//Median of Stream of Running Integers using STL
/*
    Input: 5 10 15
    Output: 5
            7.5
            10
*/
#include <iostream>
#include<queue>
#include<functional>
#include<vector>
using namespace std;

void median(vector<float>a,int n){
    int i;
    priority_queue<float>leftMaxHeap;
    priority_queue<float,vector<float>,greater<float>>rightMinHeap;
    leftMaxHeap.push(a[0]);
    float median=a[0];
    cout<<median<<" ";
    for(i=1;i<n;i++){
        if(a[i]>median){
            rightMinHeap.push(a[i]);
        }
        else{
            leftMaxHeap.push(a[i]);
        }
        int leftSize=leftMaxHeap.size();
        int rightSize=rightMinHeap.size();
        if(leftSize==rightSize){
            median=(leftMaxHeap.top()+rightMinHeap.top())/2;
        }
        else if(abs(leftSize-rightSize)==1 && leftSize>rightSize){
            median=leftMaxHeap.top();
        }
        else if(abs(leftSize-rightSize)==1 && leftSize<rightSize){
            median=rightMinHeap.top();
        }
        else if(leftSize>rightSize){
            rightMinHeap.push(leftMaxHeap.top());
            leftMaxHeap.pop();
            median=(leftMaxHeap.top()+rightMinHeap.top())/2;
        }
        else{
            leftMaxHeap.push(rightMinHeap.top());
            rightMinHeap.pop();
            median=(leftMaxHeap.top()+rightMinHeap.top())/2;
        }
        cout<<median<<" ";
    }
}

int main()
{
    vector<float>v{5, 15, 10, 20, 3};
    median(v,v.size());
    return 0;
}
