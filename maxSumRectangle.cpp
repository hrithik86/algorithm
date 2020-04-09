/* Maximum sum rectangle
Given a 2D matrix, find the maximum sum rectangle in it.
Input:
First line of every test case consists of T test case. First line of every test case consists of 2 integers R and C , denoting number of rows and columns. Second line consists of R*C spaced integers denoting number of elements in array.

Output:
Single line output, print the Max sum forming a rectangle in a 2-D matrix

Example:
Input:
1
4 5
1 2 -1 -4 -20 -8 -3 4 2 1 3 8 10 1 3 -4 -1 1 7 -6
Ouptut:
29
*/

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int>v){
    int currSum=0,maxSum=INT_MIN;
    for(int i=0;i<v.size();i++){
        currSum+=v[i];
        if(currSum>maxSum){
            maxSum=currSum;
        }
        if(currSum<0){
            currSum=0;
        }
    }
    return maxSum;
}

int main() {
	int t;
	cin>>t;
	while(t--){
	    int r,c;
	    cin>>r>>c;
	    int **a=new int*[r+1];
	    for(int i=1;i<=r;i++){
	        a[i]=new int[c+1];
	        for(int j=1;j<=c;j++){
	            cin>>a[i][j];
	        }
	    }
	    int **prefix=new int*[r+1];
	    for(int i=0;i<=r;i++){
	        prefix[i]=new int[c+1];
	        for(int j=0;j<=c;j++){
	            prefix[i][j]=0;
	        }
	    }
	    for(int i=1;i<=r;i++){
	        for(int j=1;j<=c;j++){
	            prefix[i][j]=a[i][j]+prefix[i][j-1];
	        }
	    }
	    int maxSum=INT_MIN;
	    for(int i=1;i<=c;i++){
	        for(int j=i;j<=c;j++){
	            vector<int>v;
                for(int k=1;k<=r;k++){
                    int x=prefix[k][j]-prefix[k][i-1];
                    v.push_back(x);
                }
                maxSum=max(maxSum,kadane(v));
	        }
	    }
	    cout<<maxSum<<"\n";
	}
	return 0;
}