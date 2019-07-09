//finding min element (stream of numbers insertion & deletion) 
//Method-2
#include <iostream>
#include <stack>
using namespace std;

class Stack{
    stack<int>s;
    stack<int>aux;
public:
    void push(int x){
        s.push(x);
        if(aux.empty()){
            aux.push(x);
        }
        else{
            if(x<=aux.top()){
                aux.push(x);
            }
            else{
                aux.push(aux.top());
            }
        }
    }
    void pop(){
        s.pop();
        aux.pop();
    }
    int top()
	{
		return s.top();
	}

	// Returns number of elements in the stack
	int size()
	{
		return s.size();
	}

	// Returns true if stack is empty; false otherwise
	bool empty()
	{
		return s.empty();
	}

	// Returns the minimum element from the stack in constant time
	int min()
	{
		if (aux.empty()) {
			cout << "Stack underflow!! ";
			return -1;
		}
		
		return aux.top();
	}
};

int main()
{
    Stack s;

	s.push(6);
	cout << s.min() << '\n';	// prints 6

	s.push(7);
	cout << s.min() << '\n';	// prints 6

	s.push(8);
	cout << s.min() << '\n';	// prints 6

	s.push(5);
	cout << s.min() << '\n';	// prints 5

	s.push(3);
	cout << s.min() << '\n';	// prints 3

	s.pop();
	cout << s.min() << '\n';	// prints 5

	s.push(10);
	cout << s.min() << '\n';	// prints 5

	s.pop();
	cout << s.min() << '\n';	// prints 5

	s.pop();
	cout << s.min() << '\n';	// prints 6
    return 0;
}
