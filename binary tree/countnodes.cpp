#include <iostream>
#include <vector>

using namespace std;

class node{
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

node * preorder_create(){
    int key;
    cin>>key;
    if(key==-1){
        return NULL;
    }
    node * root; 
    root = new node(key);
    root->left = preorder_create();
    root->right = preorder_create();
    return root;
}

int count_tot_nodes(node * root){
    if(root==NULL){
        return 0;
    }
    int ret = 1+ count_tot_nodes(root->left) + count_tot_nodes(root->right);
    return ret;
}

int sum_tot_nodes(node * root){
    if(root==NULL){
        return 0;
    }
    if(root->right==NULL && root->left==NULL){
        return root->data;
    }
    int ret = root->data + sum_tot_nodes(root->left) + sum_tot_nodes(root->right);
    return ret;
}

int main(){
    node * head =NULL;
    head = preorder_create();
    cout<<sum_tot_nodes(head);
    return 0;
}