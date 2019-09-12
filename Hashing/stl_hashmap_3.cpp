#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> m;

    ///Insert
    ///M-1
    m["Mango"] = 100;

    ///M-2
    m.insert(make_pair("Apple", 150));

    ///Deletion
    m.erase("Mango");

    ///Search
    if(m.count("Apple")==1){
        cout<<"Price of Apple is "<<m["Apple"]<<endl;
    }

    m["Guava"] = m["Apple"] + 50;

    if(m.count("Guava")==0){
        cout<<"Guava doesn't exist"<<endl;
    }
    else{
        cout<<"Guava costs "<<m["Guava"]<<endl;
    }

    ///Iterators to Search
    auto f = m.find("Mango");
    if(f != m.end()){
        cout<<"Price of Mango is "<<f->second<<endl;
    }
    else{
        cout<<"Mango doesn't exist"<<endl;
    }


    return 0;
}
