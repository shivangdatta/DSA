// preorder building tree -1 for NULL
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class node{
public:
    int data;
    node *left;
    node *right;
    node (int key){
        data=key;
        left=NULL;
        right=NULL;
    }
};

node * build(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node * nodes = new node(data);
    nodes -> left = build();
    nodes -> right = build();
    return nodes;
}
void print(node * root){
    // printining roots in preorder 
    if(root==NULL){
        return ;
    }
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
}


void printIn(node * root){
    if(root==NULL){
        return;
    }
    printIn(root->left);
    cout<<root->data<<" ";
    printIn(root->right);
}

void printPost(node * root){
    if(root==NULL){
        return;
    }
    printPost(root->left);
    printPost(root->right);
    cout<<root->data<<" ";
}

// level order print

int height(node * root){
    if(root==NULL){
        return 0;
    }

    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs)+1;
}

void printlvl(node * root , int ht){
    if(root==NULL){
        return;
    }
    if(ht==1){
        cout<<root->data<<" ";
        return;
    }
    printlvl(root->left , ht-1);
    printlvl(root->right , ht-1);
    return ;
}


void print_all_lvls(node * head){
    for(int i=0 ; i<=height(head); i++){
        printlvl(head,i);
        cout<<" | "<<endl ;
    }
}
int main(){
    node * head;
    head = build();

    // print(head);
    // cout<<endl;
    // printlvl(head , 3);
    print_all_lvls(head);
    return 0;
}