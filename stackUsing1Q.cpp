//implement a stack using 1 queue
#include <bits/stdc++.h>
using namespace std;

class Stack{
    queue<int> q;
public:
    void push(int x){
        q.push(x);    
    }
    void pop(){
        int i=1,size=q.size();
        while(size>i){
            q.push(q.front());
            q.pop();
            i++;
        }
        q.pop();
    }
    int top() 
    { 
        if (q.empty()) 
            return 0; 
        return q.back(); 
    }
    int size(){
        return q.size();
    }
    
};

int main()
{
    Stack s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 
  
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
