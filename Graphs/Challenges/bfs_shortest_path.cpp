#include<iostream>
#include<map>
#include<list>
#include<queue>
#include<limits.h>                      //for INT_MAX
using namespace std;

#define inf INT_MAX
#define ll long long

/*
SAMPLE INPUT:
2
4 2
1 2
1 3
1
3 1
2 3
2
*/

class Graph{
public:
    ll V;
    ll E;
    map<ll, list<pair<ll, ll>>> m;

    Graph(ll n, ll m){
        V = n;
        E = m;
    }


    void add_edge(ll u, ll v, ll cost, bool bidir=true);

    void print_adjList();

    void BFS_single_source_shortest_path(ll src);
};

void Graph :: add_edge(ll u, ll v, ll cost=6, bool bidir){
    m[u].push_back(make_pair(v, cost));
    if(bidir){
        m[v].push_back(make_pair(u, cost));
    }
    return;
}

void Graph :: BFS_single_source_shortest_path(ll src){
    bool*visited = new bool[V]{0};

    map<ll, ll> dist;

    for(ll i=1; i<=V; i++){
        dist[i] = inf;
    }

    queue<ll> q;

    dist[src] = 0;
    visited[src] = true;
    q.push(src);

    while(!q.empty()){
        ll node = q.front();
        q.pop();

        for(auto neighbour: m[node]){
//            if(visited[neighbour.first] == false && (dist[node] + neighbour.second < dist[neighbour.first])){
            if(dist[neighbour.first]==inf){                         //both conditions will work
                dist[neighbour.first] = dist[node] + neighbour.second;
                q.push(neighbour.first);
                visited[neighbour.first] = true;
            }
        }
    }

    for(ll i=1; i<=V; i++){
        if(dist[i] == inf)
            dist[i] = -1;
        if(i != src)
//            cout<<src<<"-->"<<i<<" => "<<dist[i]<<endl;
            cout<<dist[i]<<" ";
    }
    cout<<endl;
    return;
}



void Graph :: print_adjList(){
    for(ll v=1; v<=V; v++){
        cout<<v<<"->";
        for(auto neighbour: m[v]){
            cout<<"("<<neighbour.first<<", "<<neighbour.second<<") ";
        }
        cout<<endl;
    }
    cout<<endl;
    return;
}




int main(){
    ll q;
    cin>>q;

    while(q--){
        ll n, m;
        cin>>n>>m;

        Graph g(n, m);
        for(ll i=0; i<m; i++){
           ll u, v;
            cin>>u>>v;
            g.add_edge(u, v);
        }
        ll src;
        cin>>src;

//        cout<<endl;
//        g.print_adjList();
//        cout<<endl;

        g.BFS_single_source_shortest_path(src);
    }


    return 0;
}
