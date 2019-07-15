#include<iostream>
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

    return 0;
}
