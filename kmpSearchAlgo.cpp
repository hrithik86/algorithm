// KMP Algorithm
#include <bits/stdc++.h>
using namespace std;

void computeLPS(int lps[], string pat, int m){
    int len=0;
    int i=1;
    while(i<m){
        if(pat[i]==pat[len]){
            lps[i]=len+1;
            i++;
            len++;
        }
        else{
            if(len==0){
                lps[i]=0;
                i++;
            }
            else len=lps[len-1];
        }
    }
}

void KMPSearch(string pat, string str){
    int lps[pat.size()];
    lps[0]=0;
    computeLPS(lps,pat,pat.size());
    int i=0,j=0;
    while(i<str.size()){
        if(str[i]==pat[j]){
            i++;
            j++;
        }
        if(j==pat.size()){
            cout<<i-j<<"\n";
            j=lps[j-1];
        }
        else if(str[i]!=pat[j]){
            if(j==0){
                i++;
            }
            else j=lps[j-1];
        }
    }
}

int main() {
    string str="AABAACAADAABAABA"; 
    string pat="AABA"; 
    KMPSearch(pat, str); 
    return 0; 
}
