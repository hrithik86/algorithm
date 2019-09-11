/*
Calculate Grundy Number
Calculate the Grundy Number for the given 'n' in the game.
The game starts with a number- ‘n’ and the player to move divides the number- ‘n’ with 2, 3 or 6 and then takes the floor. 
If the integer becomes 0, it is removed. The last player to move wins. 
Which player wins the game?
*/

#include <bits/stdc++.h>
using namespace std;

int calculateMex(set<int>s){
    int mex=0;
    while(s.find(mex)!=s.end()){
        mex++;
    }
    return mex;
}

int calculateGrundy(int n){
    if(n==0){
        return 0;
    }
    set<int>s;
    s.insert(calculateGrundy(n/2));
    s.insert(calculateGrundy(n/3));
    s.insert(calculateGrundy(n/6));
    return calculateMex(s);
}

int main()
{   
    int n;
    cin>>n;
    cout<<calculateGrundy(n)<<endl;
    return 0;
}
