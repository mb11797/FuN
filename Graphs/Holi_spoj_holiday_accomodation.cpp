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
        l[u].push_back(make_pair(v, cost));
        if(bidir)
            l[v].push_back(make_pair(u, cost));
    }

    int dfs_HOLI_helper(int node, bool*visited, int*count, int &ans){
        visited[node] = true;
        count[node] = 1;

        for(auto neighbour: l[node]){
            int v = neighbour.first;
            int edge_cost = neighbour.second;
            if(!visited[v]){
                count[node] += dfs_HOLI_helper(v, visited, count, ans);
                int s = count[v];
                int N = V;
                ans += 2 * min(s, N-s) * edge_cost;
            }
        }
        return count[node];
    }


    int dfs_HOLI(){
        bool*visited = new bool[V]{0};
        int*count = new int[V]{0};

        int ans=0;
        dfs_HOLI_helper(0, visited, count, ans);

        for(int i=0; i<V; i++)
            cout<<count[i]<<" ";
        cout<<endl;
        return ans;
    }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 3, 2);

    cout<<g.dfs_HOLI();

    return 0;
}
