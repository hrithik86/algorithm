// Implementation of Min and Max Heap
    
/*  Both are implemented as array or vector in memory but represented as a binary tree for understanding 
    In array children of ith node/element is 2*i and (2*i)+1 node/element.     
    Min heap:
        -> Complete binary tree
        -> children of each node is greater than its parent
    Min heap:
        -> Complete binary tree
        -> children of each node is less than its parent
*/
#include <iostream>
#include <vector>
using namespace std;

class Heap{
    bool minHeap;
    vector<int>v;
    bool compare(int a,int b){
        if(minHeap){
            return a<b;
        }
        else{
            return a>b;
        }
    }
    void heapify(int i){
        int min_index=i;
        int left=2*i;
        int right=(2*i)+1;
        int lastIndex=v.size()-1;
        if(left<=lastIndex && compare(v[left],v[min_index])){
            min_index=left;
        }
        if(right<=lastIndex && compare(v[right],v[min_index])){
            min_index=right;
        }
        if(min_index!=i){
            swap(v[i],v[min_index]);
            heapify(min_index);
        }
    } 
public:
    Heap(bool minH=true){
        minHeap=minH;
        v.push_back(-1);
    }
    void push(int d){
        v.push_back(d);
        int index=v.size()-1;
        while(index>1 && compare(v[index],v[index/2])){
            swap(v[index],v[index/2]);
            index=index/2;
        }
    }
    int getTop(){
        if(v.size()>1){
            return v[1];
        }
    }
    void pop(){
        int index=v.size()-1;
        swap(v[1],v[index]);
        v.pop_back();
        heapify(1);
    }
    int size(){
        return v.size()-1;
    }
    bool isEmpty(){
        return v.size()==1;
    }
};

int main()
{
    Heap h;         //if want a max heap replace this statement with Heap h(false);
    int i;
    int a[]={7,6,5,4,3,1,2,9,10,15};
    int n=sizeof(a)/sizeof(a[0]);
    for(i=0;i<n;i++){
        h.push(a[i]);
    }
    cout<<"Min Heap:";
    while(!h.isEmpty()){
        cout<<h.getTop()<<" ";
        h.pop();
    }
    return 0;
}
