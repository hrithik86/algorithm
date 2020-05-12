/*
Inversion Count
Let A[0 ... n-1] be an array of n distinct positive integers. 
If i < j and A[i] > A[j] then the pair (i, j) is called an inversion of A (where i and j are indexes of A). 
Given an integer array A, your task is to find the number of inversions in A.
Input format :
Line 1 : n, array size
Line 2 : Array elements (separated by space).
Output format :
Count of inversions
Constraints :
1 <= n <= 10^5
1 <= A[i] <= 10^9
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Sample Input 2 :
5
2 5 1 3 4
Sample Output 1 :
4
*/

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005

long long merge(int a[],int left,int mid,int right){
    int c=0;
    int k=0;
    int i=left,j=mid+1;
    int temp[right-left+1];
    while(i<=mid && j<=right){
        if(a[i]>a[j]){
        	c+=mid-i+1;
            temp[k++]=a[j++];
        }
        else{
            temp[k++]=a[i++];
        }
    }
    while(i<=mid){
        temp[k++]=a[i++];
    }
    while(j<=right){
        temp[k++]=a[j++];
    }
    for(int j=left,k=0;j<=right;j++,k++){
        a[j]=temp[k];
    }
    return c;
}

long long mergeSort(int a[],int left,int right){
    if(left<right){
        int mid=(left+right)/2;
    	long long ans1=mergeSort(a,left,mid);
        long long ans2=mergeSort(a,mid+1,right);
        long long ans3=merge(a,left,mid,right);
        return ans1+ans2+ans3;
    }
    else return 0;
}

long long solve(int A[], int n)
{
	return mergeSort(A,0,n-1);
}

int main()
{
	int n,A[MAXN];
	cin>>n;
	for(int i = 0; i < n ; i++){
		cin>>A[i];
	}
	cout<<solve(A,n)<<endl;
}
