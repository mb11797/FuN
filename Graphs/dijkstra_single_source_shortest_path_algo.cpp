#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

template<typename T>
class Graph{
public:
    unordered_map<T, list<pair<T, int> > > m;

    void add_edge(T u, T v, int dist, bool bidir=true){
        m[u].push_back(make_pair(v, dist));
        if(bidir){
            m[v].push_back(make_pair(u, dist));
        }
    }

    void print_adjList(){
        //printing the adjacency list
        //iterate all the key value pairs

        for(auto i: m){
            cout<<i.first<<"-->";
            for(auto neighbour: m[i.first]){
                cout<<"("<<neighbour.first<<", "<<neighbour.second<<") ";
            }
            cout<<endl;
        }
        return;
    }

};

int main(){
//    Graph<int> g;
//    g.add_edge(1, 2, 1);
//    g.add_edge(1, 3, 4);
//    g.add_edge(1, 4, 7);
//    g.add_edge(2, 3, 1);
//    g.add_edge(4, 3, 2);
//
//    g.print_adjList();

    Graph<string> g1;
    g1.add_edge("Amritsar", "Delhi", 1);
    g1.add_edge("Amritsar", "Jaipur", 4);
    g1.add_edge("Delhi", "Jaipur", 2);
    g1.add_edge("Delhi", "Agra", 1);
    g1.add_edge("Jaipur", "Mumbai", 8);
    g1.add_edge("Agra", "Bhopal", 2);
    g1.add_edge("Mumbai", "Bhopal", 3);

    g1.print_adjList();

    return 0;
}
