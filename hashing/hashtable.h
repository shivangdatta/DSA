#include <iostream>
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

template <typename T>

class node{
// private:
public:
    string key;    
    T value;
    node <T> *next;
    node( string k , T val){
        key = k;
        value = val;
    }
    ~node(){
        if(next!=NULL){
            delete next;
        }
    }
};


template <typename T>
class HashTable {
private:
    int cursize;
    int tablesize;
    node <T>**buckets;

    int hashfunc(string key){
        int len = key.length();
        int final=0;
        int pow = 1;
        for(int i=0 ; i < len ; i++){
            final = final + key[len - i -1] * pow ;
            pow = pow * len ;

            pow = pow % tablesize;
            final = final % tablesize;
        }
        return final;
    }

    node ** rehashing(){
        node <T> ** oldbuckets = buckets;
         
    }

public:

    HashTable(int size = 7){
        cursize = 0;
        tablesize = size;
        buckets = new node<T> *[tablesize];
        for(int i =0 ; i<tablesize ; i++){
            buckets[i] = NULL;
        }
    }


    void insert(string key , int data){
        int index = hashfunc(key);
        node<T> * temp = new node <T> (key , data );
        temp -> next = buckets[index];
        buckets[index] = temp;      
        cursize++;

        float loadfactor = float(cursize)/float(totalsize);
        if(loadfactor >= 0.7){
            buckets = rehashing();
        }
    }

    void print(){
        for(int i = 0 ; i < tablesize ; i++){
            cout<<"data at bucket "<<i<<" is :- ";
            node<T> * temp = buckets[i];
            while(temp!=NULL){
                cout<<temp->key<<" has value : "<<temp->value<<" || ";
                temp=temp->next;
            }
            cout<<endl;
        }
    }
    node <T> * search(string key){
        int index = hashfunc(key);
        node<T> * temp = buckets[index];

        while(temp!=NULL){
            if(temp->key == key){
                // element found
                return temp;
                temp=temp->next;
            }
        }
        return NULL;
    }

    void remove(string key){
        int index = hashfunc(key);
        node <T> * temp = buckets[i];

        if(temp->key == key){
            node <T> * delme = temp;
            if(temp->next!=NULL){
                temp = temp ->next;
            }
            delete delme;
        }

        while(temp->next!=NULL){
        
            if(temp->next->key == key){
                node <T> * delme = temp->next;
                temp->next = temp->next->next;
                delete delme;
            }
            temp=temp->next;
        }
    }
};