//implement a stack using 2 queues
#include <bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q1;
    queue<int> q2;
public:
    void push(int x){
        q1.push(x);    
    }
    void pop(){
        while(q1.size()!=1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        queue<int> q = q1; 
        q1 = q2; 
        q2 = q;
    }
    int top() 
    { 
        if (q1.empty()) 
            return 0; 
        return q1.back(); 
    }
    int size(){
        return q1.size();
    }
    
};

int main()
{
    Stack s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 
    s.push(4); 
  
    cout << "current size: " << s.size()  
         << endl; 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    s.pop(); 
    cout << s.top() << endl; 
    cout << "current size: " << s.size()  
         << endl; 
    return 0; 
}
