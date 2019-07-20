#include<iostream>
#include<algorithm>
using namespace std;

class Edge{
public:
    int src;
    int dest;
    int weight;
};

bool cmp(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

void kruskals(Edge*input, int n, int e){
    sort(input, input+e, cmp);
    Edge*output = new Edge[n-1];
}

int main(){
    int n, e;
    cin>>n>>e;

    Edge*input = new Edge[e];
    for(int i=0; i<e; i++){
        int s, d, w;
        cin>>s>>d>>w;
        input[i].src = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    return 0;
}
