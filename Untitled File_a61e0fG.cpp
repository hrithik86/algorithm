//C++ program to demostrate reference variables
#include <iostream>
using namespace std;

int main()
{   int x=50;
    int &y=x;       //y is a reference variable here. Variables x and y share the same memory location now.
    x++;y++;        
    cout <<"x="<<x<< endl;
    cout <<"y="<<y<< endl;
    int *memx;      //memx is a pointer variable 
    memx=&x;        //pointing to variable x
    cout<<"Memory location of x ="<<memx<<endl;
    int *memy;      //memy is a pointer variable 
    memy=&y;        //pointing to variable y
    cout<<"Memory location of y ="<<memy<<endl;
    return 0;
}
