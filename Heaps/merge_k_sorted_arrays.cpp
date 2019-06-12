#include<iostream>
#include<vector>
#include<functional>
#include<queue>
using namespace std;


class myCompare{
public:
    bool operator()(pair<int, char> p1, pair<int, char> p2){
        return p1.first > p2.first;
    }
};

pair<int, char> p;
priority_queue<pair<int, char>, vector<pair<int, char>>, myCompare> pq;


int*merge_k_sorted_arrays(int a[], int b[], int c[], int n, int r[], int k, int cs, int ri){
    if(ri == k*n-1){
        return r;
    }


    if(a[0]<b[0]){
        p.first = a[0];
        p.second = 'a';
    }
    else{
        p.first = b[0];
        p.second = 'b';
    }

    if(c[0]<p.first){
        p.first = c[0];
        p.second = 'c';
    }

    if(cs<k){
        pq.push(p);
        if(p.second=='a'){
            return merge_k_sorted_arrays(a+1, b, c, n, r, k, cs+1, ri);
        }
        if(p.second=='b'){
            return merge_k_sorted_arrays(a, b+1, c, n, r, k, cs+1, ri);
        }
        if(p.second=='c'){
            return merge_k_sorted_arrays(a, b, c+1, n, r, k, cs+1, ri);
        }
    }
    else{
        r[ri] = pq.top().first;
        pq.pop();
        pq.push(p);
        if(p.second=='a'){
            return merge_k_sorted_arrays(a+1, b, c, n, r, k, cs, ri+1);
        }
        if(p.second=='b'){
            return merge_k_sorted_arrays(a, b+1, c, n, r, k, cs, ri+1);
        }
        if(p.second=='c'){
            return merge_k_sorted_arrays(a, b, c+1, n, r, k, cs, ri+1);
        }
    }
}


int main(){
    int a[10], b[10], c[10];
    int n;
    cin>>n;

    int k=3;

    for(int i=0; i<n; i++)
        cin>>a[i];
    for(int i=0; i<n; i++)
        cin>>b[i];
    for(int i=0; i<n; i++)
        cin>>c[i];

    int*r = new int[40];


    r = merge_k_sorted_arrays(a, b, c, n, r, k, 0, 0);

    for(int i=0; i<3*n; i++)
        cout<<r[i]<<" ";

    return 0;
}
