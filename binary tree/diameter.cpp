#include <iostream>
#include <vector>
#include <stack>
// diameter - largest dist b/w any two nodes 
using namespace std;

class node{
public:
    int data;
    node * left;
    node * right;
    node (int key){
        data=key;
        left=NULL;
        right=NULL;
    }
};


int height(node * root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left,right)+1;
}

int diameter(node * root){
    if(root==NULL){
        return 0;
    }
    int hl = height(root->left);
    int hr = height(root->right);
    int h1 = hl + hr;

    int h2 = diameter(root->right);

    int h3 = diameter(root->left);

    return max(h1,max(h2,h3));
}

class returner{
    public:
        int height;
        int diameter;
        // returner(int key , int val){
        //     height = key;
        //     diameter = val;
        // }
};

returner fast_diameter(node *root){
    returner r;
    if(root == NULL){
        r.diameter = 0;
        r.height = 0;
        return r;
    }

    returner left = fast_diameter(root->left);
    returner right = fast_diameter(root->right);

    r.height = max(left.height, right.height) + 1;
    r.diameter = max(max(left.height, right.height), max (left.diameter, right.diameter));

    return r;
}
int main(){

    return 0;
}