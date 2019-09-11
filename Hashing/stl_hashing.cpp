#include<iostream>
#include<unordered_map>
using namespace std;

int main(){
    unordered_map<string, int> my_map;

    //3 ways to insert in map:L

    //1:
    my_map["Banana"] = 120;
    my_map["Apple"] = 200;

    //2:
    my_map.insert(make_pair("Guava", 150));

    //3:
    pair<string, int> p("Pineapple", 180);
    my_map.insert(p);

    //Print
    //M-1
    for(auto node: my_map){
        cout<<node.first<<", "<<node.second<<endl;
    }

    cout<<endl;

    //M-2
    for(pair<string, int> node: my_map){
        cout<<node.first<<", "<<node.second<<endl;
    }

    return 0;
}
