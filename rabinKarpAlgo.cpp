// Rabin Karp Algorithm
// Coding Blocks

#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define prime 119

ll createHash(string s, ll n){
    ll res=0;
    for(ll i=0;i<n;i++){
        res+=(s[i]*pow(prime,i));
    }
    return res;
}

bool check(string s,string pat,int index){
    for(int i=0;i<pat.size();i++){
        if(pat[i]!=s[index]){
            return false;
        }
        index++;
    }
    return true;
}

ll reCalculateHash(ll oldhash,string s,ll m,ll prevChar,ll nextChar){
    ll res=oldhash-s[prevChar];
    res=res/prime;
    res+=(s[nextChar]*pow(prime,m-1));
    return res;
}   

int main() {
    string str="AABAACAADAABAABA",pat="AABA";
    int n=str.size();
    int m=pat.size();
    ll pathash=createHash(pat,m);
    ll substrhash=createHash(str,m);
    for(ll i=0;i+m<=n;i++){
        if(pathash==substrhash && check(str,pat,i)){
            cout<<i<<"\n";
        }
        if(i+m<n){
            substrhash=reCalculateHash(substrhash,str,m,i,i+m);
        }
    }
    return 0;
}
