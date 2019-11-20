#include<iostream>
#include<climits>
using namespace std;

#define ll long long

ll find_min_box_idx(ll*box, ll k){
    ll min_val = INT_MAX;
    ll min_idx = -1;
    for(ll i=0; i<k; i++){
        if(box[i] < min_val){
            min_val = box[i];
            min_idx = i;
        }
    }
    return min_idx;
}

bool different_distribution(ll n, ll k){
    ll box_cand1[k] = {0};
    ll box_cand2[k] = {0};

    //candidate 1 style filling
    for(ll i=0; i<n/k; i++){
        for(ll j=0; j<k; j++){
            box_cand1[j] += 1;
        }
    }

    //candidate 2 style filling
    while(n>0){
        ll min_box_idx = find_min_box_idx(box_cand2, k);

        if(n > k){
            box_cand2[min_box_idx] += k;
            n -= k;
        }
        else{
            box_cand2[min_box_idx] += n;
            n -= n;
        }
    }

    for(ll i=0; i<k; i++){
        if(box_cand1[i] != box_cand2[i])
            return true;
    }
    return false;
}


int main(){
    ll tc;
    cin>>tc;

    while(tc--){
        ll n, k;
        cin>>n>>k;

        if(different_distribution(n, k))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }

    return 0;
}
