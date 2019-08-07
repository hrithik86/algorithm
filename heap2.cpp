//STL heap implementation
#include <iostream>
#include<queue>
#include<functional>
#include<cstring>
using namespace std;

class Person{
public:    char name[100];
    int money;

    Person(){
    }
    Person(char*n,int m){
        strcpy(name,n);
        money=m;
    }
};

class PersonCompare{
    public:
        bool operator()(const Person &p1,const Person &p2){
            return p1.money>p2.money;
        }
};

int main()
{   
    priority_queue<int>pq;          //By default it gives max heap, to get min heap replace this statement
                                    //with priority_queue<int,vector<int>,greater<int>>pq
    int a[]={7,6,5,4,3,1,2,9,10,15}; 
    int n=sizeof(a)/sizeof(a[0]);
    for(int i=0;i<n;i++){
        pq.push(a[i]);
    }
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    
    priority_queue<Person,vector<Person>,PersonCompare>pp;
    Person p1("hrithik",100);
    Person p2("rishabh",1);
    Person p3("ayush",2);
    pp.push(p1);
    pp.push(p2);
    pp.push(p3);
    
    // PersonCompare t;
    // bool ans=t(p1,p2);
    // cout<<"answer="<<ans;
    
    while(!pp.empty()){
        Person tp=pp.top();
        cout<<tp.name<<" "<<tp.money<<endl;
        pp.pop();
    }
    return 0;   
}
