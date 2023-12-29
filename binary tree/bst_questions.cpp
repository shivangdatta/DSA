#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
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

node * create_node(node * root , int key){
    if(root==NULL){
        return new node (key);
    }
    if(root->data < key){
        root->right = create_node(root->right , key);
    }
    if(root->data > key){
        root->left = create_node(root->left , key);
    }
    return root;
}



node * build_tree(){
    int key;
    cin>>key;
    node *root =NULL;
    while(key!=-1){
        root = create_node(root , key);
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




// questions start here
// deletion 

node * delete_node(node * root , int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data == key){
        // 3cases = 0 child , 1 child , 2 child
        // case 1
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }
        // case 2 
        if(root->left!=NULL || root->right!=NULL){
            if(root->right == NULL){
                node * temp = root->left;
                delete root;
                return temp;
            }
            if(root->left == NULL){
                node * temp = root->right;
                delete root;
                return temp;
            }

        }
        // case 3 
        if(root->left!=NULL && root->right!=NULL){
            node * temp = root->right;
            while(temp->left!=NULL){
                temp=temp->left;
            }
            root->data=temp->data;
            return delete_node(temp , key);
        }

    }
    if(root->data < key){
        root->right = delete_node(root->right , key);
    }
    if(root->data > key){
        root->left = delete_node(root->left , key);
    }
    return root;
}


// check if given tree is a bst or not
/* function not working
class checker{
public: 
    int max_left;
    bool check;
    int min_right;
};

checker is_bst(node * root){
    checker c0;
    if(root==NULL){
        c0.check = true;
        c0.max_left = INT_MIN;
        c0.min_right = INT_MAX;
        return c0;
    }
    checker left , right;
    if(root->left==NULL && root->right==NULL){
        left.max_left = root->data;
        right.min_right = root->data;
        left.check = right.check = true;
    }
    
    //left call 
    left = is_bst(root->left);
    // right call
    right = is_bst(root->right);

    c0.max_left = left.max_left;
    c0.min_right = right.min_right;
    if(c0.max_left<=root->data && c0.min_right>=root->data  && left.check == true && right.check == true){
        c0.check = true;
        return c0;
    }
    c0.check = false;

    return c0;
}

*/

bool isbst(node * root , int left = INT_MIN , int right = INT_MAX ){
    if(root==NULL){
        return true;
    }
    if(left <=root->data && root->data<=right && isbst(root->left ,left , root->data ) && isbst(root->right , root->data , right)){
        return true;
    }
    return false;
}

// convert a bst to linked list (sorted)

class linkedlist{
    public: 
        node * head;
        node * tail;
};

linkedlist convert_to_linked(node * root){
    linkedlist l0;
    if(root==NULL){
        l0.head = l0.tail = NULL;
        return l0;
    }
    // base case 2
    if(root->left==NULL && root->right==NULL){
        l0.head = root;
        l0.tail = root;
        return l0;
    }
    // case 1 := right empty
    linkedlist leftl;
    linkedlist rightl;
    if(root->left!=NULL && root->right==NULL){
        leftl = convert_to_linked(root->left);
        leftl.tail->right = root;

        l0.head = leftl.head;
        l0.tail = root;
        return l0;
    }
    // case2 := left empty
    if(root->right!=NULL && root->left==NULL){
        rightl = convert_to_linked(root->right);
        root->right = rightl.head;

        l0.head = root;
        l0.tail = rightl.tail;
        return l0;
    }
    // case 3 : both lst and rst present 
    if(root->right!=NULL && root->left!=NULL){
        leftl = convert_to_linked(root->left);
        rightl = convert_to_linked(root->right);

        leftl.tail->right = root ;
        root->right = rightl.head;

        l0.head = leftl.head;
        l0.tail = rightl.tail;
    }
    return l0;
}


// form a bst from preorder/postorder 

node * pre_to_bst(int * pre , int * in ,int start , int end ){
    static int i = 0;
    if(start>end){
        return NULL;
    }
    node * root=new node(pre[i]);
    int index = -1 ;
    for(int j=0 ; j<=end ; j++){
            if(pre[i] == in[j]){
                index = j;
                break;
            }
        }
    i++;
    root->left = pre_to_bst(pre , in , start , index-1);
    root->right = pre_to_bst(pre , in , index+1 , end);
    return root;
}

int main(){
    // node * head = NULL;
    // head = build_tree();
    // bfs_newline(head);
    // // delete_node(head , 5);
    // // bfs_newline(head);
    // // node * temp = new node(100);
    // // head->left=temp;
    // if(isbst(head)){
    //     cout<<"yes"<<endl;
    // }
    // bfs_newline(head);

    int pre[] = {10 , 5 , 1 , 8 , 15 , 12 , 18};
    int in[7];
    for(int i =0 ; i<7 ; i++){
        in[i] = pre[i];
    }
    sort(in , in+7);
    // for(int k =0 ; k<7 ; k++){
    // //     cout<<pre[k]<<" ";
    // //     // cout<<in[k]<<" ";
    // // }
    node * root = pre_to_bst(pre , in , 0 , 6);
    bfs_newline(root);
    return 0;
}