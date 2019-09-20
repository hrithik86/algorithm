//Computational Geometry
//Area of a polygon
#include <bits/stdc++.h>
using namespace std;

class Point{
    public:
        double x,y;
};
class Polygon{
    public:
    Point *points;
    //parameterized constructor
    Polygon(int n){
        points=new Point[n];
    }
};
double area(Polygon p,int n){
    double fArea=0;
    int i=1;
    double x1=p.points[0].x;
    double y1=p.points[0].y;
    while(i+1<n){
        double X1=p.points[i].x-x1;
        double Y1=p.points[i].y-y1;
        double X2=p.points[i+1].x-x1;
        double Y2=p.points[i+1].y-y1;
        double cross_p=(X1*Y2)-(Y1*X2);
        fArea+=cross_p;
        i++;
    }
    return abs(fArea/2);
};
int main()
{
    int n;
    cin>>n;
    Polygon p(n);
    for(int i=0;i<n;i++){
        cin>>p.points[i].x;
        cin>>p.points[i].y;
    }
    cout<<"Area of polygon="<<area(p,n)<<endl;
    return 0;
}
