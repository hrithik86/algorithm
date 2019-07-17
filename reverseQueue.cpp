//Reversing a Queue using Recursion

#include <bits/stdc++.h>
using namespace std;

void reverse(queue<int>&q){
    if(q.empty()){
        return;
    }
    int t=q.front();
    q.pop();
    reverse(q);
    q.push(t);
}

void print(queue<int>q){
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();    
    }
}

int main()
{
    queue<int>q;
    for(int i=1;i<=4;i++)
        q.push(i);
    print(q);
    reverse(q);
    cout<<"\n";
    print(q);
    return 0;
}
