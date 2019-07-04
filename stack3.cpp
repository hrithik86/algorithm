//Stack implementation 3
#include <iostream>
#include <cstring>
//#include"stack.h"         we write this to include our own header file, 
//we would have written this line if class stack was saved in another file with extension of ".h"  
using namespace std;

template<typename T>
class Vector{
    T *arr;
    int cs;
    int ms;
public:
    Vector(int s=4){
        arr=new T[s];
        cs=0;
        ms=s;
    }
    void push_back(const T d){
        if(cs==ms){
            //expand the vector if full
            T*oldArr=arr;
            int oldSize=ms;
            ms=ms<<1;
            arr=new T[ms];
            for(int i=0;i<cs;i++){
                arr[i]=oldArr[i];
            }
            delete [] oldArr;
            oldArr=NULL;
        }
        arr[cs]=d;
        cs++;
    }
    void pop_back(){
        if(cs>0){
            cs--;
        }
    }
    int size() const{
        return cs;
    }
    int capacity() const{
        return ms;
    }
    T operator[] (int i){
        return arr[i];
    } 
};

template<typename T1>
class Stack{
    Vector<T1> v;
public:
    void push(T1 data){
        v.push_back(data);
    }
    void pop(){
        v.pop_back();
    }
    T1 top(){
        return v[v.size()-1];
    }
    bool isEmpty(){
        return v.size()==0;
    }
    int size(){
        return v.size();
    }
};

class Book{
public:
    int price;
    char name[20];
    
    Book(){}
    Book(int p,char n[20]){
        price=p;
        strcpy(name,n);
    }
    void print(){
        cout<<price<<endl;
        cout<<name<<endl;
    }
};

int main()
{   
    Stack<int>s;
    for(int i=1;i<=5;i++){
        s.push(i*i);
    }
    while(!s.isEmpty()){
        cout<<s.top()<<endl;
        s.pop();
    }
    Stack<Book> sb;
    Book b1(100,"C++");
    Book b2(200,"java");
    Book b3(300,"pyhton");
    sb.push(b1);
    sb.push(b2); 
    sb.push(b3);
    while(!sb.isEmpty()){
        Book tp=sb.top();
        tp.print();
        sb.pop();
    }
    return 0;
}
