//finding square root of a number using binary search
#include <bits/stdc++.h>
using namespace std;

float binarySearch(int num,int p){
    float res;
    int m,s=0,l=num;
    
    while(s<=l){
        m=(s+l)/2;
        if((m*m)>num){
            l=m-1;
        }
        else if((m*m)==num){
            return m;
        }
        else{
            res=m;
            s=m+1;
        }
    }
        //floating point
        float i;
        int place;
        for(place=1,i=0.1;place<=p;place++,i=i*0.1){
            while(1){
                res=res+i;
                if((res*res)>num){
                    res=res-i;
                    break;
                }
                
            }    
        // cout<<"Loop "<<place<<":"<<res<<"\n";
        }
    return res;
}

int main()
{
    int num,p;                  //p is the precision i.e., the no. of digits after the decimal point
    cin>>num>>p;
    float ans=binarySearch(num,p);
    cout<<ans;
    return 0;
}
