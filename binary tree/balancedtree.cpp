#include <iostream>
#include <stdio.h>
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

// checking if given tree is balanced or not 
pair <int , bool> is_balanced(node * root){
    pair <int ,bool> p1 ;
    if(root==NULL){
        p1.first=0;
        p1.second=true;
        return p1;
    }

    pair left = is_balanced(root->left);
    pair right = is_balanced(root->right);
    
    p1.first = max(left.first,right.first)+1;
    if(abs(left.first - right.first)<=1 && left.second && right.second){
        p1.second=true;
    }
    else{
        p1.second=false;
    }
    return p1 ;
} 


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

// building a balanced tree given values in array

node * build_balance(int * arr , int start , int end){
    if(start>=end){
        return NULL;
    }
    // recursive case
    int mid=(start+end)/2;
    node * root = new node (arr[mid]);
    root->left = build_balance(arr , start , mid);
    root->right = build_balance(arr, mid+1 , end);

    return root;
}

// build a binary tree given post order/ peroder and in order traversal traversal

node * pre_builder(int *pre , int *in , int start , int end ){
    static int i =  0 ;
    if(start > end){
        return NULL;
    }
    node * root = new node (pre[i]);
    int index=-1;
    for(int j = 0 ; start<=end ; j++ ){
        if(pre[i]==in[j]){
            index = j; 
            break;
        }
    }
    i++;
    root -> left = pre_builder(pre , in , start , index-1);
    root -> right = pre_builder(pre , in , index+1 , end);
    return root;
}


void bfs(node * root){
    queue <node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node * temp = q.front();
        if(temp==NULL){
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
    node * head =NULL;
    // head = preorder_build();
    // int  arr[7] = {1,2,3,4,5,6,7};
    // head = build_balance(arr, 0 , 7);
    // pair <int, bool> test;
    // test = is_balanced(head);
    // if(test.second){
    //     cout<<"Balanced "<<endl;
    // }
    // else{
    //     cout<<"Not Balanced"<<endl;
    // }
    int  pre[] = {1,2,3,4,8,5,6,7};
    int  in[] = {3,2,8,4,1,6,7,5};
    head = pre_builder(pre , in , 0 , 7);
    bfs(head);
    return 0;
}