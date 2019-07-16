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

    void addEdge(int u, int v, int cost, bool bidir=true){
        l[u].push_back(make_pair(u, v));
    }

};

int main(){
    Graph g(5);


    return 0;
}
