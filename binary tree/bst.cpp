#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node {
public:
    int data;
    node * left;
    node * right;

    node (int key){
        data = key;
        left = NULL;
        right = NULL;
    }
};



node * add_node(node * root,int key){
    if(root==NULL){
        return new node(key);
    }
    if(root->data < key ){
        root->right = add_node(root->right , key);
    }
    if(root->data > key ){
        root->left = add_node(root->left , key);
    }
    return root;
}

node * build_tree(){
    int key;
    cin>>key;
    node *root =NULL;
    while(key!=-1){
        root = add_node(root , key);
        cin>>key;
    }
    return root;
}



void bfs_newline(node * root){
    queue <node *> que;
    que.push(root);
    que.push(NULL);
    while(!que.empty()){
        node * temp = que.front();
        if(temp==NULL){
            cout<<endl;
            que.pop();
            if(!que.empty()){
                que.push(NULL);
            }
        }
        else{
            que.pop();
            if(temp->left!=NULL){
                que.push(temp->left);
            }
            if(temp->right!=NULL){
                que.push(temp->right);
            }
            cout<<temp->data<<" ";
        }
    }
}


bool search(node * root , int key){
    if(root==NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    if(root->data < key){
        return search(root->right , key);
    }
    if(root->data > key){
        return search(root->left , key);
    }
}


int main(){
    node * head = NULL ;
    head = build_tree();
    bfs_newline(head);
    if(search(head , 78)){
        cout<<"yes";
    }
    return 0;
}