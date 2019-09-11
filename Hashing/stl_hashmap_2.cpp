#include<iostream>
#include<unordered_map>
using namespace std;

class Fruit{
public:
    string name;
    int price;
    string city;
public:
    Fruit(){

    }

    Fruit(string n, int p, string c){           //default constructor is overwritten, so we have to define default constructor ourselves bcz of garbage datatype in hashtable.h file
        name = n;
        price = p;
        city = c;
    }
};


int main(){
    unordered_map<string, Fruit> my_map;
    Fruit f("Mango", 100, "Delhi");

    my_map[f.name] = f;

    Fruit f_search = my_map["Mango"];

    cout<<f_search.city<<endl;
    cout<<f_search.price<<endl;

    return 0;
}
