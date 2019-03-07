/*Tower of Hanoi using recursion
There are 3 towers. Aim is to move the disks from tower 1 to tower 3.
Rules:
    1.Only one disk can be moved in one step.
    2.At each step, make sure the bigger disks are below the smaller ones.  
*/

#include <iostream>
using namespace std;
int i=1;
void toh(int n,char src,char helper,char dest){
    //Base Case
    if(n==0){
        return;
    }
    //Recursive Case
    else{
        toh(n-1,src,dest,helper);                                               //takes (n-1) steps
        cout<<"Step"<<i<<":Move the "<<n<<" disk from "<<src<<" to "<<dest;     //takes 1 step
        cout<<endl;                                                             //takes (n-1) steps
        i++;
        toh(n-1,helper,src,dest);
    }
}

int steps(int n){
    if(n==0){
        return 0;
    }
    else{
        return 2*steps(n-1)+1;
    }
}

int main()
{   int n,moves; 
    cin>>n;
    toh(n,'A','B','C');
    moves=steps(n);
    cout<<"Number of steps taken:"<<moves;
    //No. of steps are (2^n -1) also can be written as (1<<n)-1
    return 0;
}
