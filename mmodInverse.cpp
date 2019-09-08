//Multiplicative Modulo Inverse(application of Extended Euclid's Algo)
//(a*b) mod m =1
//given a and m find b.

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

int mmInverse(int a,int m){
    Triplet ans=extendedEuclid(a,m);
    return ans.x;
}

int main()
{   
    int a=5,m=17;
    cout<<mmInverse(a,m)<<endl;
    return 0;
}
