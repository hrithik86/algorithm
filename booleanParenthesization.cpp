// Boolean Parenthesization Problem: DP
// O(N*N*N) approach
// Video Reference: Pepcoding
#include <bits/stdc++.h>
using namespace std;

int countWays(int N, string S){
    string chars="";
    string ops="";
    for(int i=0;i<N;i++){
        if(i&1) ops+=S[i];
        else chars+=S[i];
    }
    int n=chars.size();
    int trueTable[n][n];
    int falseTable[n][n];
    for(int gap=0;gap<n;gap++){
        for(int i=0,j=gap;j<n;i++,j++){
            if(gap==0){
                char ch=chars[i];
                if(ch=='T'){
                    trueTable[i][j]=1;
                    falseTable[i][j]=0;
                }
                else{
                    trueTable[i][j]=0;
                    falseTable[i][j]=1;
                }
            }
            else{
                trueTable[i][j]=0;
                falseTable[i][j]=0;
                for(int k=i;k<j;k++){
                    char opr=ops[k];
                    int ltc=trueTable[i][k];
                    int rtc=trueTable[k+1][j];
                    int lfc=falseTable[i][k];
                    int rfc=falseTable[k+1][j];
                    if(opr=='&'){
                        trueTable[i][j]+=(ltc*rtc);
                        falseTable[i][j]+=(ltc*rfc)+(lfc*rtc)+(lfc*rfc);
                    }
                    else if(opr=='|'){
                        trueTable[i][j]+=(ltc*rfc)+(lfc*rtc)+(ltc*rtc);
                        falseTable[i][j]+=(lfc*rfc);
                    }
                    else{
                        trueTable[i][j]+=(ltc*rfc)+(lfc*rtc);
                        falseTable[i][j]+=(ltc*rtc)+(lfc*rfc);
                    }
                }
            }
        }
    }
    return trueTable[0][n-1];
}

int main() {
    string s="T^F&T";
    int n=5;
    cout<<countWays(n,s);
    return 0;
}
