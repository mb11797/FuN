#include<iostream>
#include<list>
using namespace std;

class Graph{
    int V;
    list<pair<int, int>> *l;
public:
    Graph(int v){
        V = v;
        l = new list<pair<int, int>>[V];
    }

};

int main(){
    Graph g(5);


    return 0;
}
