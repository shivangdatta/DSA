#include <iostream>
#include <stdio.h>
#include <queue>
// replace each node by sum of childrem node

using namespace std;

class node{
public:
    int data;
    node * left;
    node * right;
    node (int key){
        data=key;
        left = NULL;
        right = NULL;
    }
};

node * build(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node * root = new node(data);
    root -> left = build();
    root -> right = build();
    return root;
}

int sumfinder(node * root){
    int key;
    key = root->left->data + root->right->data;
    return key;
}

void change_to_sum(node * root){
    if(root->left==NULL && root->right==NULL ){
        return ;
    }
    change_to_sum(root->left);
    change_to_sum(root->right);
    root->data=sumfinder(root);
}
// replace parent by sum of all the children nodes 

class returner{
public:
    int data;
    int left;
    int right;
};

returner change_to_sumall(node *root){
    returner r0;
    if(root==NULL){
        r0.data = 0;
        r0.left = 0;
        r0.right = 0;
        return r0;
    }
    if(root->right==NULL && root->left==NULL){
        r0.data = root->data;
        r0.left = 0;
        r0.right = 0;
        return r0;
    }

    returner left = change_to_sumall(root->left);
    returner right = change_to_sumall(root->right);
    r0.data=root->data;
    root->data = left.data + right.data ;
    r0.data=root->data+r0.data;
    return r0;
}

// done in much simpler way

int change_to_sumall2(node *root){
    if(root==NULL){
        return 0;
    }
    if(root->right == NULL && root->left ==NULL){
        return root->data;
    }
    int left = change_to_sumall2(root->left);
    int right = change_to_sumall2(root->right);
    int temp = root->data;
    root->data = left + right;
    return temp + root->data;
}

void printlvl(node * root){
    queue <node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * temp = q.front();
        if(q.front()==NULL){
            q.pop();
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            cout<<temp->data<<" ";
        }
    }

}
int main(){
    node * head = NULL;
    head=build();
    printlvl(head);
    change_to_sumall(head);
    printlvl(head);
    return 0 ;
}