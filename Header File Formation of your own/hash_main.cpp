#include<iostream>
#include"hashtable.h"
using namespace std;

int main(){
    //Fruit, 100     key = string, price = int

    Hashtable<int> h(7);
//    Hashtable<int> h(11);

    h.insert("Mango", 100);
    h.insert("Apple", 170);
    h.insert("Guava", 140);
    h.insert("Banana", 130);
    h.insert("Chiku", 120);
    h.insert("Grapes", 200);
    h.insert("Lichi", 160);
    h.insert("Orange", 150);

    h.print();

    cout<<endl;

    string f;
    cin>>f;

    int*price = h.search(f);
    if(price==NULL)
        cout<<"Not Found!!!"<<endl;
    else
        cout<<"Price is "<<*price<<endl;

    cout<<endl;

    h.erase(f);
//    h.erase("Chiku");
    h.print();

    h["Pineapple"] = 350;
    h["Grapes"] = 500;

    h.print();
    cout<<endl;

    cout<<h["Pineapple"]<<endl;
    cout<<h["Grapes"]<<endl;
    cout<<h["Banana"]<<endl;


    return 0;
}
