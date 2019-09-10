#include<iostream>
#include<cstring>
using namespace std;

template<typename T>
class node{
public:
    string key;
    T value;
    node<T>*next;

    node(string key, T v){
        this->key = key;
        value = v;
    }
};

template<typename T>
class Hashtable{
    int cs;         //current size
    int ts;         //Max Array size
    node<T>**buckets;

    int hashFn(string key){
        int L = key.length();
        int ans = 0;
        int p = 1;          //37^0 is 1 initially

        for(int i=0; i<L; i++){
            ans += key[L - i - 1]*p;
            p *= 37;
            p %= ts;
            ans %= ts;
        }
        return ans;
    }

public:
    Hashtable(int ds = 7){
        cs = 0;
        ts = ds;
        buckets = new node<T>*[ts];

        //make all addresses as zero initially
        for(int i=0; i<ts; i++){
            buckets[i] = NULL;
        }
    }

    void insert(string key, T value){
        //for key - i need to generate the hash index
        int i = hashFn(key);

        node<T>*n = new node<T>(key, value);
        n->next = buckets[i];
        buckets[i] = n;
        return;
    }

    //Print it
    void print(){
        //Iterate over buckets array
        for(int i=0; i<ts; i++){
            //print the linked list for each bucket
            node<T>*temp = buckets[i];
            cout<<"Bucket "<<i<<"->";
            while(temp != NULL){
                cout<<"("<<temp->key<<", "<<temp->value<<")"<<", ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    T search(string key){
        for(int i=0; i<ts; i++){
            node<T>*temp = buckets[i];
            while(temp!=NULL){
                if(temp->key == key){
                    return temp->value;
                }
                temp = temp->next;
            }
        }
        return -1;
    }
};
