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
//    my_map.insert(make_pair("Banana", new Fruit f1("Banana", 80, "Kota")));
    Fruit f1("Banana", 80, "Kota");

    my_map[f.name] = f;
    my_map.insert(make_pair(f1.name, f1));
    Fruit f_search = my_map["Mango"];

    cout<<f_search.city<<endl;
    cout<<f_search.price<<endl;

    //Count function - 0 or 1
    cout<<"Apple "<<my_map.count("Apple")<<endl;
    cout<<"Mango "<<my_map.count("Mango")<<endl;

    cout<<"Enter a fruit to search: "<<endl;
    string fruit;
    cin>>fruit;

    my_map.erase("Mango");

    if(my_map.count(fruit) != 0){
        cout<<"Price is "<<my_map[fruit].price<<endl;
    }
    else{
        cout<<fruit<<" doesnt exist!"<<endl;
    }

    return 0;
}
