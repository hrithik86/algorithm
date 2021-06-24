// LRU Cache Leetcode: O(1) time
// Hashmap + Doubly linked list(DLL)
// Reference: Striver YT video
#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    int n;
    // DLL contains nodes from most recent used to 
    // least recently used in left to right manner 
    struct Node{
        int k;
        int val;
        Node*prev;
        Node*next;
        Node(){
            k=0;
            val=0;
            prev=NULL;
            next=NULL;
        }
        Node(int key,int value){
            k=key;
            val=value;
        }
    };
    
    // Hashmap store the key to its memory 
    // location in DLL
    unordered_map<int,Node*>um;
    Node*head=NULL;Node*tail=NULL;
    LRUCache(int capacity) {
        // Initial configuration of the DLL
        head=new Node();
        tail=new Node();
        head->next=tail;
        tail->prev=head;
        n=capacity;
    }
    
    void deleteNode(int key){
        
        // Delete from DLL
        Node*currNode=um[key];
        Node*future=currNode->next;
        Node*past=currNode->prev;
        past->next=currNode->next;
        future->prev=currNode->prev;
        currNode->next=NULL;
        currNode->prev=NULL;
        delete(currNode);
        
        // Delete from hashmap
        um.erase(key);
    }
    void insertAtStart(int key,int value){
        
        // Insert at start (means after head)
        Node*startNode=head->next;
        Node*newNode=new Node(key,value);
        head->next=newNode;
        newNode->prev=head;
        newNode->next=startNode;
        startNode->prev=newNode;
        
        // Update hashmap
        um[key]=newNode;
    }
    int get(int key) {
        if(um.find(key)!=um.end()){
            // Get its value from DLL
            int value=um[key]->val;
            
            // Delete this key from Hashmap as well as DLL
            deleteNode(key);
            
            // Insert a new node with the same key value 
            // at the starting since this node is now most
            // recently used, also update the hashmap with 
            // new memory location
            insertAtStart(key,value);
            return value;
        }   
        else return -1;
    }
    void put(int key, int value) {
        if(um.size()<n){
            // If this key is already present
            if(um.find(key)!=um.end()){
                deleteNode(key);
            }
            insertAtStart(key,value);
        }    
        else{
            // If this key is already present
            if(um.find(key)!=um.end()){
                deleteNode(key);
                insertAtStart(key,value);
            }
            else{
                // Delete the LRU key
                int LRUkey=tail->prev->k;
                deleteNode(LRUkey);
                insertAtStart(key,value);
            }
        }
    }
};
int main() {
    LRUCache obj(2);
    obj.put(1,1);
    obj.put(2,2);
    cout<<obj.get(1)<<" ";
    obj.put(3,3);
    cout<<obj.get(2)<<" ";
    obj.put(4,4);
    cout<<obj.get(1)<<" ";
    cout<<obj.get(3)<<" ";
    cout<<obj.get(4)<<" ";
    return 0;
}
