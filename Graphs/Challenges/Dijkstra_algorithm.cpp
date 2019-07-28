#include<iostream>
#include<map>
#include<list>
#include<set>
using namespace std;

#define ll long long
#define inf 1e9

/*
SAMPLE INPUT 1:
1
4 4
1 2 24
1 4 20
3 1 3
4 3 12
1

SAMPLE INPUT 2:
1
94 95
1 19 56
2 57 41
3 1 32
4 1 36
5 1 24
6 19 16
7 19 25
8 76 6
9 76 23
10 19 25
11 76 64
12 19 6
13 76 12
14 76 18
15 76 47
16 1 53
17 19 36
18 19 25
19 38 55
20 1 1
21 76 57
22 1 44
23 57 19
24 38 15
25 1 16
26 19 37
27 76 22
28 57 54
29 19 47
30 76 15
31 57 5
32 19 13
33 19 65
34 1 19
35 19 17
36 38 12
37 1 5
38 19 23
39 76 33
40 38 19
41 19 4
42 76 32
43 57 27
44 57 18
45 1 13
46 19 40
47 1 62
48 76 46
49 1 18
50 19 4
51 1 58
52 1 9
53 19 5
54 57 63
55 76 29
56 1 28
57 38 26
58 19 47
59 57 43
60 76 37
61 76 14
62 1 40
63 76 27
64 1 28
65 76 32
66 1 47
67 38 21
68 76 58
69 38 10
70 38 46
71 57 59
72 1 7
73 38 55
74 57 51
75 38 45
76 77 9
77 76 46
78 38 43
79 1 61
80 57 43
81 1 2
82 19 64
83 1 9
84 1 14
85 57 49
86 57 22
87 19 12
88 76 55
89 76 26
90 1 36
91 1 63
92 57 51
93 19 7
94 1 24
55 76 9
85
*/



class Graph{
public:
    map<ll, list<pair<ll, ll>>> m;

    void add_edge(ll u, ll v, ll cost, bool bidir=true){
        m[u].push_back(make_pair(v, cost));
        if(bidir){
            m[v].push_back(make_pair(u, cost));
        }
    }

    void print(){
        for(auto i: m){
            cout<<i.first<<"->";

            for(auto neighbour: i.second){
                cout<<"("<<neighbour.first<<", "<<neighbour.second<<") ";
            }
            cout<<endl;
        }
        return;
    }

    void Dijkstra_SSSP(ll src){
        map<ll, ll> dist;

        for(auto i: m){
            dist[i.first] = inf;
        }

        dist[src] = 0;

        set<pair<ll, ll>> s;            //sec -> (cost, node)

        s.insert({0, src});

        while(not s.empty()){
            auto p = *(s.begin());
            ll node = p.second;

            ll node_dist = p.first;

            s.erase(s.begin());

            for(auto child_pair: m[node]){
                if(node_dist + child_pair.second < dist[child_pair.first]){
                    ll dest = child_pair.first;
                    auto f = s.find(make_pair(dist[dest], dest));
                    if(f != s.end()){
                        s.erase(f);
                    }

                    dist[dest] = node_dist + child_pair.second;
                    s.insert(make_pair(dist[dest], dest));

                }
            }
        }

        for(auto d: dist){
            if(d.second<0 || d.second==inf)
                d.second = -1;
            if(d.first != src)
                cout<<d.second<<" ";
        }
        cout<<endl;
        return;
    }


};


int main(){
    ll tc;
    cin>>tc;

    ll n, m;
    while(tc--){
        Graph g;
        cin>>n>>m;

        for(ll i=0; i<m; i++){
            ll u, v, cost;
            cin>>u>>v>>cost;

            g.add_edge(u, v, cost);
        }

        ll src;
        cin>>src;

//        g.print();

        g.Dijkstra_SSSP(src);
    }


//    Graph g;
//
//    g.add_edge(1, 2, 1);
//    g.add_edge(1, 3, 4);
//    g.add_edge(1, 4, 7);
//    g.add_edge(2, 3, 1);
//    g.add_edge(3, 4, 2);
//
//    g.print();

    return 0;
}
