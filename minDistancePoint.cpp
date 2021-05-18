// Optimum location of point to minimize total distance
// https://www.geeksforgeeks.org/optimum-location-point-minimize-total-distance/
#include <bits/stdc++.h>
using namespace std;

struct line{
    int a,b,c;
    line(int x,int y,int z){
        a=x;
        b=y;
        c=z;
    }
};

double distance(double x1,double y1,double x2,double y2){
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

double findDistance(vector<vector<int>>points,line l,double X){
    // find Y coordinate of point 
    double Y = -1 * (l.c + l.a * X) / l.b;
    double ans=0;
    for(int i=0;i<points.size();i++){
        ans+=distance(X,Y,points[i][0],points[i][1]);
    }
    return ans;
}

void findOptimumCost(vector<vector<int>>points,line l){
    // Setting values for X coordinate
    double low=-1e6;
    double high=1e6;
    while((high-low)>1e-6){
        double mid1=low+(high-low)/3;
        double mid2=high-(high-low)/3;
        double dist1=findDistance(points,l,mid1);
        double dist2=findDistance(points,l,mid2);
        if(dist1<dist2){
            high=mid2;
        }
        else{
            low=mid1;
        }
    }
    double ans=findDistance(points,l,(high+low)/2);
    cout<<ans;
}

int main() {
    line l(1, -1, -3);
    vector<vector<int>>points{
        { -3, -2 }, { -1, 0 }, { -1, 2 }, { 1, 2 }, { 3, 4 }
    };
    findOptimumCost(points, l);
}
