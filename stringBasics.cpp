#include <bits/stdc++.h>
using namespace std;

int main()
{   
    int t,pos,max=0,i=0;
    cin>>t; vector<string>s;
    cin.get();
    while(t--){
        char str[100];
        cin.getline(str,100);
        s.push_back(str);
        if(strlen(str)>max){
            max=strlen(str);
            pos=i;
        }
        i++;
    }
    cout<<s[pos];
    return 0;
}
