//0-1 Knapsack Problem(Bounded i.e., one item can be picked only one)
#include <bits/stdc++.h>
using namespace std;

//======================================RECURSION=======================================
int maxProfit(int n,int maxWt,int wt[],int pr[]){
    if(n==0 || maxWt==0){
        return 0;
    }
    int includedAns=0,excludedAns=0;
    
    //including the current item
    if(maxWt>=wt[n-1]){
        includedAns=pr[n-1]+maxProfit(n-1,maxWt-wt[n-1],wt,pr);         //For unbounded knapsack(one item can be picked any number of times),
                                                                        //includedAns=pr[n-1]+maxProfit(n,maxWt-wt[n-1],wt,pr);          
    }
    
    //excluding the current item
    excludedAns=maxProfit(n-1,maxWt,wt,pr);
    
    return max(includedAns,excludedAns);
}                                                                                
//========================================================================================


//================================DP======================================================
int bottomUpDP(int n,int maxWt,int wt[],int pr[]){
    int dp[100][100];
    for(int i=0;i<=n;i++){                  //i represents the number of items that can be taken
        for(int w=0;w<=maxWt;w++){          //w represents the max capacity of the bag
            if(i==0 || w==0){
                dp[i][w]=0;
            }
            else{
                int inc=0,exc=0;
                if(wt[i-1]<=w){
                    inc=pr[i-1]+dp[i-1][w-wt[i-1]]; //for uncounded knapsack,
                                                    //inc=pr[i-1]+dp[i][w-wt[i-1]];
                }
                exc=dp[i-1][w];
                dp[i][w]=max(inc,exc);
            }
        }
    }
    return dp[n][maxWt];
}
//==========================================================================================

int main()
{
    int n=4;
    int wt[]={2,2,3,1};
    int pr[]={5,20,100,30};
    int maxWt=5;
    cout<<maxProfit(n,maxWt,wt,pr)<<endl;
    cout<<bottomUpDP(n,maxWt,wt,pr);
    return 0;
}
