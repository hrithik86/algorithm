/* Largest rectangular sub-matrix whose sum is 0 
Another similar question: Largest area rectangular sub-matrix with equal number of 1’s and 0’s
Idea: just replace 0 with -1 and find the largest rectangular sub-matrix whose sum is 0 
*/
#include <bits/stdc++.h>
using namespace std;

int maxSubarrayWith0Sum(vector<int>A)
{
    int n=A.size();
    unordered_map<int,int>um;
    int sum=0;
    int len=0;
    for(int i=0;i<n;i++){
        sum+=A[i];
        if(sum==0){
            len=max(len,i+1);
            continue;
        }
        if(um.find(sum)!=um.end()){
            len=max(len,i-um[sum]);
        }
        else um[sum]=i;
    }
    return len;
}

int largestAreaWith0Sum(vector<vector<int> > &A) {
    int ans=0;
    int n=A.size();
    if(n==0) return 0;
    int m=A[0].size();
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            A[i][j]+=A[i][j-1];
        }
    }
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            vector<int>v;
            for(int k=0;k<n;k++){
                int x=A[k][j];
                if(i>=1) x-=A[k][i-1];
                v.push_back(x);
            }
            int height=maxSubarrayWith0Sum(v);
            int width=j-i+1;
            ans=max(ans,height*width);
        }
    }
    return ans;
}

int main() {
    vector<vector<int> > A{{-8, 5,  7},
                        {3,  7, -8},
                        {5, -8,  9}};
    vector<vector<int>> B{ {-1, -1, 1, 1},
                    {-1, 1, 1, -1},
                    {1, 1, 1, -1},
                    {1, -1, -1, 1} };
    cout<<largestAreaWith0Sum(A)<<"\n";
    cout<<largestAreaWith0Sum(B);
}
