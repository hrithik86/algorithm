/*
A-star Algorithm: to find shorest path between nodes

I/P:
9 10
1 0 1 1 1 1 0 1 1 1 
1 1 1 0 1 1 1 0 1 1 
1 1 1 0 1 1 0 1 0 1 
0 0 1 0 1 0 0 0 0 1 
1 1 1 0 1 1 1 0 1 0 
1 0 1 1 1 1 0 1 0 0 
1 0 0 0 0 1 0 0 0 1 
1 0 1 1 1 1 0 1 1 1 
1 1 1 0 0 0 1 0 0 1
8 0
0 0

O/P:
(8,0) -> (7,0) -> (6,0) -> (5,0) -> (4,1) -> (3,2) -> (2,1) -> (1,0) -> (0,0) -> 

*/

#include <bits/stdc++.h>
using namespace std;

int k[]={-1,0,1};

struct cell{
    int parent_i,parent_j;
    double g,h,f;
};

double heuristic(pair<int,int>p1,pair<int,int>p2){
    //euclidean distance
    return sqrt(pow(p1.first-p2.first,2)+pow(p1.second-p2.second,2));
}

bool isValid(int i,int j,int r,int c){
    if(i<0 || i>=r || j<0 || j>=c){
        return false;
    }
    return true;
}

bool isDest(int x1,int y1,int x2,int y2){
    if(x1==x2 && y1==y2) return true;
    return false;
}

void tracePath(cell **cellDetails,int X,int Y){
    if(X!=-1 && Y!=-1){
        int temp1=cellDetails[X][Y].parent_i;
        int temp2=cellDetails[X][Y].parent_j;
        tracePath(cellDetails,temp1,temp2);
        cout<<"("<<X<<","<<Y<<") -> ";        
    }
}

void astar(int **grid,pair<int,int>src,pair<int,int>dest,int r,int c){
    //each node having f value and the node coordinates
    set<pair<double,pair<int,int>>>openList;
    bool closeList[r][c];
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            closeList[i][j]=false;
        }
    }
    cell **cellDetails=new cell*[r];
    for(int i=0;i<r;i++){
        cellDetails[i]=new cell[c];
        for(int j=0;j<c;j++){
            cellDetails[i][j].parent_i=-1;
            cellDetails[i][j].parent_j=-1;
            cellDetails[i][j].g=FLT_MAX;
            cellDetails[i][j].h=FLT_MAX;
            cellDetails[i][j].f=FLT_MAX;
        }
    }
    int I=src.first;
    int J=src.second;
    cellDetails[I][J].g=0;
    cellDetails[I][J].h=heuristic(src,dest);
    cellDetails[I][J].f=cellDetails[I][J].g+cellDetails[I][J].h;

    openList.insert({cellDetails[I][J].f,{I,J}});
    
    while(!openList.empty()){
        auto current=openList.begin();
        int X=current->second.first;
        int Y=current->second.second;

        if(isDest(X,Y,dest.first,dest.second)){    
            //Trace Path
            tracePath(cellDetails,X,Y);
            return;
        }

        //remove from open set
        openList.erase(current);
        //push in closeList
        closeList[X][Y]=true;
        
        //go to neighbors
        for(int i=0;i<3;i++){
            int a=k[i];
            for(int j=0;j<3;j++){
                int b=k[j];
                if(a==0 && b==0) continue;
                if(isValid(X+a,Y+b,r,c)){
                    if(!closeList[X+a][Y+b] && grid[X+a][Y+b]!=0){
                        int tempG=cellDetails[X][Y].g+1.0;
                        if(openList.find({cellDetails[X+a][Y+b].f,{X+a,Y+b}})!=openList.end()){     //present in openList
                            if(tempG<cellDetails[X+a][Y+b].g){          //update in the openList
                                auto pos=openList.find({cellDetails[X+a][Y+b].f,{X+a,Y+b}});
                                openList.erase(pos);
                                cellDetails[X+a][Y+b].parent_i=X;
                                cellDetails[X+a][Y+b].parent_j=Y;
                                cellDetails[X+a][Y+b].g=tempG;
                                cellDetails[X+a][Y+b].h=heuristic({X+a,Y+b},dest);
                                cellDetails[X+a][Y+b].f=cellDetails[X+a][Y+b].g+cellDetails[X+a][Y+b].h;
                                //insert in the openList
                                openList.insert({cellDetails[X+a][Y+b].f,{X+a,Y+b}});
                            }
                        }
                        else{       //not in openList
                            if(tempG<cellDetails[X+a][Y+b].g){
                                cellDetails[X+a][Y+b].parent_i=X;
                                cellDetails[X+a][Y+b].parent_j=Y;
                                cellDetails[X+a][Y+b].g=tempG;
                                cellDetails[X+a][Y+b].h=heuristic({X+a,Y+b},dest);
                                cellDetails[X+a][Y+b].f=cellDetails[X+a][Y+b].g+cellDetails[X+a][Y+b].h;
                            }
                            //insert in the openList
                            openList.insert({cellDetails[X+a][Y+b].f,{X+a,Y+b}});
                        }
                    }
                }
            }
        }
    }
    cout<<"No path found\n";
    return;
}

int main() {
    int r,c;
    cin>>r>>c;
    int **grid=new int*[r];
    for(int i=0;i<r;i++){
        grid[i]=new int[c];
        for(int j=0;j<c;j++){
            cin>>grid[i][j];
        }
    }
    int src_i,src_j,dest_i,dest_j;
    cin>>src_i>>src_j>>dest_i>>dest_j;
    pair<int,int>src={src_i,src_j};
    pair<int,int>dest={dest_i,dest_j};
    astar(grid,src,dest,r,c);
}