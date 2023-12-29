#include <iostream>

using namespace std;
template <typename T>
class node {
public:
    string key;
    T data;
    node * next;
    node(string key , T val){
        this->key = key;
        data = val;
        next = NULL;
    }
};

template <typename T>
class re_hashtable{
private:
    int cursize;
    int tablesize;
    node <T> ** buckets;

    int hashfunc(string key){
        int pow = 1;
        int ans = 0;
        for(int i = key.length()-1 ; i>=0 ; i++){
            ans += ans + key[i]*pow;
            pow=pow*37;

            pow = pow % tablesize;
            ans = ans % tablesize;
        }
        ans = ans % tablesize;
        return ans;
    }

    void rehashing(){
        node <T> ** oldbuckets = buckets;
        int oldsize = tablesize;
        int newsize = 2 * tablesize ;
        

        re_hashtable(newsize);
        for(int i = 0 ; i < oldsize i++){
            node * temp = oldbuckets[i];
            while(temp!=NULL){
                insert(temp->key , temp->value)
                temp = temp->next;
            }
        }
    }
public:
    re_hashtable(int ts = 11){
        tablesize = ts ;
        cursize = 0 ;
        buckets = new node <T> *[tablesize];
        for(int i = 0 ; i<tablesize ; i++){
            buckets[i]=NULL;
        }
    }
    void insert(string key , T data){
        int index = hashfunc(key);
        node <T> * temp;
        temp = new node<T>(key , data);
        temp->next = buckets[index];
        bucket[i] = temp;

        float loadfactor;
        loadfactor = float(cursize) / float(tablesize);

        if(loadfactor >= 0.7){
            rehashing();
        }

    }
    void printall(){
        for(int i = 0 ; i<tablesize ; i++){
            node * temp = buckets[i];
            while(temp!=NULL){
                cout<<"key : "<<temp->key<<" data : "<<temp->key;
                cout<<" || ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
};