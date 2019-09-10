#include<iostream>
#include"hashtable.h"
using namespace std;

int main(){
    //Fruit, 100     key = string, price = int

    Hashtable<int> h;
//    Hashtable<int> h(11);

    h.insert("Mango", 100);
    h.insert("Apple", 170);
    h.insert("Guava", 140);
    h.insert("Banana", 130);
    h.insert("Chiku", 120);

    h.print();

    return 0;
}
