//checking if 2 strings are permutations of each other
#include <bits/stdc++.h>
using namespace std;

int main()
{   
    string str1,str2;int i,flag=1;
    cin>>str1>>str2;
    if(str1.length()!=str2.length()){
        cout<<"Not permutations of each other";
    }
    else{
        int freq[256]={0};
        for(i=0;i<str1.length();i++){
            freq[str1[i]]++;
            freq[str2[i]]--;
        }
        for(i=97;i<123;i++){
            if(freq[i]!=0){
                flag=0;
                break;
            }
        }
        if(flag==0) cout<<"Not permutations of each other";
        else cout<<"Permutations";
    }
    return 0;
}
