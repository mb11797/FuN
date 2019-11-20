#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;

/*
SAMPLE INPUT:
1
30 4 4
3 22
5 8
11 26
20 29
17 4
19 7
21 9
27 1
*/


class Graph{
public:
    int V, E;
    map<int, list<int>> m;

    Graph(int n){
        V = n;
    }

    void add_edge(int s, int d, bool bidir);

    void print_adjList();

    int bfs_shortest_path(int src, int dest);
};

void Graph :: add_edge(int s, int d, bool bidir=true){
    m[s].push_back(d);
    if(bidir)
        m[d].push_back(s);
    return;
}

void Graph :: print_adjList(){
    for(int i=1; i<=V; i++){
        cout<<i<<"--->";
        for(auto neighbour: m[i]){
            cout<<neighbour<<", ";
        }
        cout<<endl;
    }
    return;
}


int Graph :: bfs_shortest_path(int src, int dest){
    queue<int> q;
    map<int, int> dist;
    map<int, int> parent;

    for(auto i: m){
        dist[i.first] = INT_MAX;
    }

    dist[src] = 0;
    parent[src] = src;
    q.push(src);

    while(not q.empty()){
        int node = q.front();
        q.pop();

        for(auto neighbour: m[node]){
//            if(dist[neighbour]==INT_MAX){
            if(dist[node] + 1 < dist[neighbour]){                       //both conditions will work
                dist[neighbour] = dist[node] + 1;
                parent[neighbour] = node;
                q.push(neighbour);
            }
        }
    }
//    //printing the shortest way
//    int temp;
//    for(temp = dest; temp != src; temp = parent[temp]){
//        cout<<temp<<"<--";
//    }
//    cout<<src<<endl;
    return dist[dest];
}

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n, l, s;
        cin>>n>>l>>s;

        Graph g(n);
        int board[50] = {0};

        int u, v;
        for(int i=0; i<l; i++){
            cin>>u>>v;
            board[u] = v - u;
        }

        for(int i=0; i<s; i++){
            cin>>u>>v;
            board[u] = v - u;
        }

        //constructing the graph by adding pairs of (u, v)
        for(int s=1; s<=n; s++){
            for(int dice=1; dice<=6; dice++){
                int d = s + dice + board[s + dice];
                g.add_edge(s, d, false);
            }
        }

//        g.print_adjList();
        int min_dice_throws_to_reach_last_cell = g.bfs_shortest_path(1, n);
        cout<<min_dice_throws_to_reach_last_cell<<endl;
    }


    return 0;
}
