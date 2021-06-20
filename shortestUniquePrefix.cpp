// Shortest unique prefix: Codestudio
// Trie Solution
#include <bits/stdc++.h>
using namespace std;

struct Node{
    Node*children[26];
    bool isLeaf;
    int cnt;
    Node(){
        for(int i=0;i<26;i++) children[i]=NULL;
        isLeaf=false;
        cnt=1;
    }
};

void insert(Node*root,string s){
    Node*temp=root;
    for(int i=0;i<s.size();i++){
        int index=s[i]-'a';
        if(temp->children[index]==NULL){
            Node*newnode=new Node();
            temp->children[index]=newnode;
            temp=newnode;
        }
        else{
            temp=temp->children[index];
            temp->cnt+=1;
        }
    }
    temp->isLeaf=true;
}

string findUniquePrefix(Node*root,string s){
    // Move to the first character
    Node*temp=root->children[s[0]-'a'];
    string str="";
    for(int i=1;i<s.size();i++){
        str+=s[i-1];
        if(temp->cnt==1){
            return str;
        }
        else{
            int index=s[i]-'a';
            temp=temp->children[index];
        }
    }
    if(temp->isLeaf) str+=s[s.size()-1];
    return str;
}

vector<string> shortestUniquePrefix(vector<string> s, int n) {
    vector<string>ans;
    Node*root=new Node();
    for(int i=0;i<n;i++){
        insert(root,s[i]);
    }
    for(int i=0;i<n;i++){
        string str=findUniquePrefix(root,s[i]);
        ans.push_back(str);
    }
    return ans;
}

int main() {
    vector<string>s{"many","mango","mad"};
    int n=s.size();
    vector<string>ans=shortestUniquePrefix(s,n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<"\n";
    }
    return 0;
}
