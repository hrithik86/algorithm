// Ladders' Problem
//           _TOP
//         _|
//       _|
//     _|
//   _|    
// _|
// There are n stairs and we can take a jump/step of 1,2 or 3 at once.Determine the total 
// number of ways to reach the top.
#include<bits/stdc++.h> 
using namespace std; 
  
  
//======================================RECURSION===============================================  
int noWays(int stairs,int steps,vector<int>v,int count=0){
    if(stairs==0){
        count++;
        // Printing ways
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        return count;
    }
    if(stairs<0){
        return count;
    }
    for(int j=1;j<=steps;j++){
        v.push_back(j);
        count=noWays(stairs-j,steps,v,count);
        v.pop_back();
    }
    return count;
}


//time O(k^n)
int ways(int n,int k){
    //Ground
    if(n==0) 
        return 1;
    if(n<0) 
        return 0;
    int ans=0;
    for(int j=1;j<=k;j++){
        ans+=ways(n-j,k);
    }
    return ans;
}  
//============================================================================================== 
 
 
//Bottom Up DP O(nk)
int BottomUpDP(int n,int k){
    int *m=new int[n];
    m[0]=1;
    for(int i=1;i<=n;i++){
        m[i]=0;
        for(int j=1;j<=k;j++){
            if(i-j>=0){
                m[i]+=m[i-j];    
            }    
        }
    }
    return m[n];
}  

//O(n)
int effApproach(int n,int k){
    int *m=new int[n];
    m[0]=1;
    for(int i=1;i<=n;i++){
        m[i]=0;
        if(i-k>0){
            m[i]=(2*m[i-1])-m[i-k-1];    
        }else{
            for(int j=1;j<=k;j++){
                if(i-j>=0){
                    m[i]+=m[i-j];    
                }    
            }
        }
        
    }
    return m[n];
}  
 
int main() 
{  
    vector<int>v;
    int stairs=5;
    int steps=3;            //i.e., 1 , 2, and 3 jump possible at once
    cout<<"Number of ways to reach top="<< noWays(stairs,steps,v);
    cout<<endl;
    cout<<"Number of ways to reach top="<< ways(stairs,steps);
    cout<<endl;
    cout<<"Number of ways to reach top="<<BottomUpDP(stairs,steps);
    cout<<endl;
    cout<<"Number of ways to reach top="<<effApproach(stairs,steps);
    return 0; 
} 