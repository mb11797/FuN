#include<iostream>
#include<unordered_map>
#include<list>
#include<set>
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
        cout<<endl;
        return;
    }

    void Dijkstra_SSSP(T src){
        unordered_map<T, int> dist;

        //initially setting all distances to infinity
        for(auto i: m){
            dist[i.first] = INT_MAX;
        }

        //making a set to find out a node with the minimum distance
        set<pair<int, T> > s;           //sorting in set is done on the basis of the first parameter

        dist[src] = 0;
        s.insert(make_pair(0, src));

        while(!s.empty()){
            //find the pair at the front
            auto p = *(s.begin());
            T node = p.second;

            int node_dist = p.first;
            s.erase(s.begin());

            //iterate over the neighbours/children of the current node
            for(auto child_pair: m[node]){
                if(node_dist + child_pair.second < dist[child_pair.first]){
                    //In a set, updation of a particular node is not possible,
                    //we have to remove the old pair and insert the new pair to do simultaneous updation
                    T dest = child_pair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f != s.end()){                //if f is found in the set
                        s.erase(f);
                    }

                    //Insert the new updated pair
                    dist[dest] = node_dist + child_pair.second;
                    s.insert(make_pair(dist[dest], dest));
                }
            }
        }
        // Finally Print distance to all nodes from source node
        for(auto d: dist){
            cout<<d.first<<" is located at a minimum distance of "<<d.second<<" from "<<src<<endl;
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
    cout<<endl;
    g1.Dijkstra_SSSP("Amritsar");

    return 0;
}
