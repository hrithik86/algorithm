/* 
Median in a row-wise sorted Matrix
Reference: Striver Youtube Video(Take U forward)
Time Complexity: O(32 * R * log(C))
Auxiliary Space: O(1)
*/
#include <bits/stdc++.h>
using namespace std;

int binSearch(vector<int>v,int c,int x){
    int low=0,high=c-1;
    int ans=-1;
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]>x){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return ans;
}
int findNumbers(vector<vector<int>> &matrix, int r, int c,int mid){
    int ans=0;
    for(int i=0;i<r;i++){
        if(matrix[i][c-1]<=mid) ans+=c;
        else if(matrix[i][0]>mid) continue;
        else{
            int x=binSearch(matrix[i],c,mid);    
            ans+=x;    
        }
    }
    return ans;
}
int median(vector<vector<int>> &matrix, int r, int c){
    int low=1;
    int high=1e9;
    int x=(r*c)/2;
    int ans=0;
    while(low<=high){
        int mid=low+(high-low)/2;
        int numLessthanEqualMid=findNumbers(matrix,r,c,mid);
        if(numLessthanEqualMid<=x){
            low=mid+1;
        }
        else{
            ans=mid;
            high=mid-1;
        }
    }
    return ans;
}
int main() {
    vector<vector<int>>matrix{{1, 3, 5}, 
     {2, 6, 9}, 
     {3, 6, 9}};
     int r=3;
     int c=3;
     cout<<median(matrix,r,c);
}
