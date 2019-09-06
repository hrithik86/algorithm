//Extended Euclid's Algorithm
//used to find integral value of x,y for equation:
//        ax+by=gcd(a,b)

#include <iostream>
using namespace std;

class Triplet{
    public:
    int x;
    int y;
    int gcd;
};

Triplet extendedEuclid(int a,int b){
    if(b==0){
        Triplet ans;
        ans.x=1;
        ans.gcd=a;
        ans.y=0;
        return ans;
    }
    Triplet smallerAns=extendedEuclid(b,a%b);
    Triplet ans;
    ans.gcd=smallerAns.gcd;
    ans.x=smallerAns.y;
    ans.y=smallerAns.x-(a/b)*smallerAns.y;
    return ans;
}

int main()
{   
    int a=16,b=10;
    Triplet ans=extendedEuclid(a,b);
    cout<<"GCD:"<<ans.gcd<<endl;
    cout<<"x:"<<ans.x<<endl;
    cout<<"y:"<<ans.y<<endl;
    
    return 0;
}
