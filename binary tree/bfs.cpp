#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class node{
public : 
    int data;
    node * right;
    node * left;
    node (int key){
        data=key;
        right=NULL;
        left=NULL;
    }
};

node * preorder_build(){
    int key;
    cin>>key;

    if(key==-1){
        return NULL;
    }
    node * root = new node(key);
    root->left=preorder_build();
    root->right=preorder_build();
    return root;
}

int max_height(node * root){
    if(root==NULL){
        return 0;
    }
    int left = max_height(root->left);
    int right = max_height(root->right);
    return max(left,right)+1;
}


void bfs(node * root){
    queue <node *> q;
    q.push(root);
    while(!q.empty()){
        node * temp = q.front();
        q.pop();
        if(temp->left!=NULL){
            q.push(temp->left);
        }    
        if(temp->right!=NULL){
            q.push(temp->right);
        }
        cout<< temp->data << " ";
    }
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

int main(){
    node * head=NULL;
    head = preorder_build();
    bfs(head);
    cout<<endl;
    bfs_newline(head);
    return 0;
}