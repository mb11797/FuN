#include<iostream>
#include<algorithm>
using namespace std;

int find_max_pairs(int n, int d, int L[]){
    sort(L, L+n);

    int pairs=0;
    int i=1;
    while(i<n){
        if(L[i] - L[i-1] <= d){
            pairs++;
            i += 2;
        }
        else{
            i += 1;
        }
    }
    return pairs;
}

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n_chopsticks;
        cin>>n_chopsticks;

        int max_diff;
        cin>>max_diff;

        int sticks_length[n_chopsticks];
        for(int i=0; i<n_chopsticks; i++)
            cin>>sticks_length[i];

        cout<<find_max_pairs(n_chopsticks, max_diff, sticks_length)<<endl;
    }
    return 0;
}
