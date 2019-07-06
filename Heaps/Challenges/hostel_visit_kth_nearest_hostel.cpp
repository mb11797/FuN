#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

/* Input format:
9 3
1 10 10
1 9 9
1 -8 -8
2
1 7 7
2
1 6 6
1 5 5
2
*/

#define ll long long

void hostel_visit(ll nq, ll k){
    priority_queue<ll> pq;
    ll cs=0;
    while(nq--){
        ll q;
        cin>>q;

        if(q==1){
            ll x, y;
            cin>>x>>y;
            ll d = pow(x-0, 2) + pow(y-0, 2);
            if(cs<k){
                pq.push(d);
                cs++;
            }
            else{
                pq.pop();
                pq.push(d);
            }
        }
        else if(q==2){
            cout<<pq.top()<<endl;
        }
    }
    return;
}

int main(){
    ll nq;
    cin>>nq;

    ll k;
    cin>>k;

    hostel_visit(nq, k);

    return 0;
}


