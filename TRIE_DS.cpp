/*  
TRIE DATA STRCUTURE

If there are thousands of strings and we want to search a string,
then in worst case it would take O(m*len) time.
where m is total no. of strings and len is the length of the string which we are looking for.
Basically, we are comparing each string with the string we are looking for.

IN THIS CASE, TRIE data structure searches for the element in constant time,i.e.,
O(len)

*/
#include <iostream>
#include<unordered_map>
#include<cstring>
using namespace std;

#define um unordered_map<char,node*>

class node{
public:
    char data;
    um m;
    bool isTerminal;
    
    node(char d){
        data=d;
        isTerminal=false;
    }
};

class Trie{
    node*root;
public:
    Trie(){
        root=new node('\0');
    }
    void addWord(char *word){
        node*temp=root;
        for(int i=0;word[i]!='\0';i++){
            char ch=word[i];
            if(temp->m.count(ch)){
                temp=temp->m[ch];
            }
            else{
                node*n =new node(ch);
                temp->m[ch]=n;
                temp=n;
            }
        }
        temp->isTerminal=true;
        return;
    }
    bool search(char*word){
        node*temp=root;
        for(int i=0;word[i]!='\0';i++){
            char ch=word[i];
            if(temp->m.count(ch)==0){
                return false;
            }
            else{
                temp=temp->m[ch];
            }
        }
        return temp->isTerminal;
    }
};

int main()
{
    Trie t;
    char words[][100]={"apple","apen","not","no","news","code"};
    for(int i=0;i<6;i++){
        t.addWord(words[i]);
    }
    char s[]="apple";
    if(t.search(s)){
        cout<<"found";
    }
    else cout<<"not found";
    return 0;
}
