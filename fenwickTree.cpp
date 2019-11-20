//Fenwick tree or Binary Indexed Tree

#include <iostream>
using namespace std;

void update(int idx,int val,int*biTree,int n){
    while(idx<=n){
        biTree[idx]+=val;
        idx=idx+(idx&(-idx));           //get next
    }
    return;
}

int query(int idx,int*biTree){
    int sum=0;
    while(idx>0){
        sum+=biTree[idx];
        idx=idx-(idx&(-idx));           //get parent
    }
    return sum;
}

int main()
{
    int n;
    cin>>n;
    int *arr=new int[n+1]{};
    int *biTree=new int[n+1]{};
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        update(i,arr[i],biTree,n);
    }
    cout<<"Sum of first 5 elements:"<<query(5,biTree)<<endl;
    cout<<"Sum of elements from 2 index to 6 index:"<<query(6,biTree)-query(1,biTree)<<endl;
    
    
    return 0;
}
