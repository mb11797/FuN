#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
using namespace std;

template<typename T>
class Graph{
public:
    unordered_map<T, list<pair<T, int>>> m;

    void add_edge(T u, T v, int dist, bool bidir=true){
        m[u].push_back(make_pair(v, dist));
        if(bidir){
            m[v].push_back(make_pair(u, dist));
        }
        return;
    }

    void print_adjList(){
        for(auto i: m){
            cout<<i.first<<"-->";
            for(auto neighbour: i.second){
                cout<<"("<<neighbour.first<<", "<<neighbour.second<<") ";
            }
            cout<<endl;
        }
        cout<<endl;
        return;
    }

    void Dijkstra_SSSP(T src){
        unordered_map<T, int> dist;

        for(auto i: m){
            dist[i.first] = INT_MAX;
        }

        set<pair<int, T>> s;

        dist[src] = 0;
        s.insert(make_pair(0, src));

        while(!s.empty()){

            auto p = *(s.begin());
            int node_dist = p.first;
            T node = p.second;
            s.erase(s.begin());

            for(auto child_pair: m[node]){
                if(node_dist + child_pair.second < dist[child_pair.first]){
                    //update the distance in dist map

                    //first find the pair in the set s and then erase it
                    T dest = child_pair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f != s.end()){
                        s.erase(f);
                    }

                    //insert the new updated pair
                    dist[dest] = node_dist + child_pair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }

        //Finally print distance to all the nodes from source nodes
        for(auto d: dist){
            cout<<d.first<<" is located at a distance of "<<d.second<<" from "<<src<<endl;
        }
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
    cout<<endl;
    g1.Dijkstra_SSSP("Amritsar");

    return 0;
}
