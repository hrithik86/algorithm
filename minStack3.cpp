//finding min element in O(1) time and O(1) extra space
#include <bits/stdc++.h>
using namespace std;

class Stack{
    stack<int> s;
    int min;
public:
    void push(int x){
        if(s.empty()){
            min=x;
            s.push(x);
            return;
        }
        if(x>=min){
            s.push(x);
        }
        else{
            int m=(2*x)-min;
            s.push(m);
            min=x;
        }
    }
    void pop(){
        if(s.top()>=min){
            s.pop();
        }
        else{
            min=(2*min)-s.top();
            s.pop();
        }
    }
    int top() 
    { 
        if (s.empty()) 
            return -1; 
        return s.top(); 
    }
    
    int size(){
        return s.size();
    }
    void getMin() 
    { 
        if (s.empty()) 
            cout << "Stack is empty\n"; 
  
        // variable min stores the minimum element 
        // in the stack. 
        else
            cout <<"Minimum Element in the stack is: "
                 << min << "\n"; 
    } 
    
};

int main()
{
    Stack S; 
    S.push(3);
    S.getMin(); 
    S.push(5); 
    S.getMin(); 
    S.push(2);
    S.getMin(); 
    S.push(1); 
    S.getMin(); 
    S.pop(); 
    S.getMin(); 
    S.pop(); 
    S.getMin(); 
    return 0; 
}
