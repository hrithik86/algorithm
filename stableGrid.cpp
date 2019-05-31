/*You are given a grid with R rows (numbered 1 through R) and C columns (numbered 1 through C). A cell in row r and column c is denoted by (r,c). Two cells in the grid are adjacent if they have a common side. For each valid i and j, there is a value ai,j written in cell ai,j.

A cell in the grid is stable if the number of cells in the grid which are adjacent to this cell is strictly greater than the value written in this cell. The whole grid is stable if all cells in the grid are stable.

Can you determine whether the grid is stable?

Input
The first line of the input contains a single integer T denoting the number of test cases. The description of T test cases follows.
The first line of each test case contains two space-separated integers R and C.
R lines follow. For each i (1≤i≤R), the i-th of these lines contains C space-separated integers ai,1,ai,2,…,ai,C.
Output
For each test case, print a single line containing the string "Stable" if the grid is stable or "Unstable" if it is unstable (without quotes).

Constraints
1≤T≤3,000
3≤R,C≤10
0≤ai,j≤4 for each valid i,j
Example Input
2
3 3
1 2 1
2 3 2
1 2 1
3 4
0 0 0 0
0 0 0 0
0 0 4 0
Example Output
Stable
Unstable
*/
#include <iostream>
using namespace std;

int nearCells(int r,int c,int m,int n){
    int x=0;
    if(m>0){
        x++;
    }
    if(n>0){
        x++;
    }
    if(m<r){
        x++;
    }
    if(n<c){
        x++;
    }
    return x;
}

void IsStable(int a[10][10],int r,int c,int m=0,int n=0){
    if(m>r){
        cout<<"Stable"<<endl;
        return;
    }
    int adjCells=nearCells(r,c,m,n);
    if(adjCells>a[m][n]){
        n++;
        if(n>c){
            n=0;
            m++;
        }
        IsStable(a,r,c,m,n);
    }
    else{
        cout<<"Unstable"<<endl;
        return;
    }
}

int main()
{   
    int i,j,t,r,c,a[10][10];
    cin>>t;
    while(t--){
        cin>>r>>c;
        for(i=0;i<r;i++){
            for(j=0;j<c;j++){
                cin>>a[i][j];
            }
        }
        r--;c--;
        IsStable(a,r,c);
    }
    return 0;
}
