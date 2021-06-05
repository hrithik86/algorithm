// 123. Best Time to Buy and Sell Stock III
// Max profit in atmost 2 transactions
// Reference: Techdose video
// T.C: O(N), S.C: O(N)
#include <bits/stdc++.h>
using namespace std;

// Divide and conquer approach
// The idea is to divide the array at each point 
// and find the max profit in the left part and 
// max profit in the right part, such that
// it results in two transactions.
// And we know how to find the max profit in 1
// transaction.
// left[i] stores the max profit of 1 transaction
// in array[0...i]
// right[i] stores the max profit of 1 transaction
// in array[i...n]
int maxProfit(vector<int>& a) {
    int n=a.size();
    int left[n];
    int right[n];
    left[0]=0;
    right[n-1]=0;
    int leftmin=a[0];
    for(int i=1;i<n;i++){
        if(a[i]<leftmin){
            leftmin=a[i];
        }
        left[i]=max(left[i-1],a[i]-leftmin);
    }
    int rightmax=a[n-1];
    for(int i=n-2;i>=0;i--){
        if(a[i]>rightmax){
            rightmax=a[i];
        }
        right[i]=max(right[i+1],rightmax-a[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=max(ans,left[i]+right[i]);            
    }
    return ans;
}
int main() {
    vector<int>a{1,2,3,4,5};
    cout<<maxProfit(a);
    return 0;
}
