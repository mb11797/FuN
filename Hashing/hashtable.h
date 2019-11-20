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

    //Recursive destructor
    ~node(){
        if(next != NULL){
            delete next;        ///recursive call to the destructor again and again 
        }
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

    void rehash(){
        node<T>** old_buckets = buckets;
        int old_ts = ts;
        ts = ts*2 + 1;          //try choosing a prime no bigger than twice the ts
        cs = 0;

        buckets = new node<T>*[ts];
        for(int i=0; i<ts; i++){
            buckets[i] = NULL;
        }

        //Read the elements from old table and insert them in new table
        for(int i=0; i<old_ts; i++){
            node<T>*temp = old_buckets[i];

            if(temp != NULL){
                while(temp != NULL){
                    insert(temp->key, temp->value);
                    temp = temp->next;
                }
                //delete the old_bucket's ith bucket linked list
                delete old_buckets[i];          //for this to work, we have to write the recursive destructor in node class
            }
        }
        delete [] old_buckets;          //array deletion syntax
        return;
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

        cs++;

        float load_factor = (float) cs/ts;
        if(load_factor > 0.7){
            cout<<"Load Factor is: "<<load_factor<<endl;
            rehash();
        }

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

    T* search(string key){
        int i = hashFn(key);
        node<T>*temp = buckets[i];
        while(temp!=NULL){
            if(temp->key == key){
                return &(temp->value);          //bcz return type is an address
            }
            temp = temp->next;
        }
        //What if key is not found? T can Fruit or string or int or Book, etc anything
        return NULL;
    }

    void erase(string key){
        int i = hashFn(key);
        node<T>*temp = buckets[i];
        node<T>*prev = buckets[i];
        if(temp->key == key){
            buckets[i] = temp->next;
            delete temp;
            return;
        }
        prev = temp;
        temp = temp->next;
        while(temp != NULL){
//            cout<<"1"<<endl;
            if(temp->key == key){
//                cout<<"INSIDE"<<endl;
                prev->next = temp->next;  
                break;
            }
            prev = temp;
//            cout<<"2"<<endl;
            temp = temp->next;
        };
        delete temp;
        return;
    }

    T& operator[](string key){
        T*temp = search(key);
        if(temp == NULL){
            //Insertion
            T garbage;
            insert(key, garbage);

            T*value = search(key);
            return *value;
        }

        //else return the box (update/search functionality)
        return *temp;
    }
};
