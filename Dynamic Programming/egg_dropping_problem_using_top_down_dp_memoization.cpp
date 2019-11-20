#include<iostream>
#include<cstring>
using namespace  std;

int memo[1000][1000];               //(n_eggs, n_floors)

int min_trials_in_worst_case(int nf, int ne){
    if(nf==0 || nf==1)
        return nf;
    if(ne == 1){
        return nf;
    }

    if(memo[ne][nf] != -1)
        return memo[ne][nf];

    int ans = INT_MAX;
    for(int i=1; i<=nf; i++){

        //if egg breaks
        int t1 = min_trials_in_worst_case(i-1, ne-1);

        //if egg does not break
        int t2 = min_trials_in_worst_case(nf-i, ne);

        ans = min(ans, 1 + max(t1, t2));
    }

    return memo[ne][nf] = ans;
}

int main(){
    memset(memo, -1, sizeof(memo));
    int nf, ne;
    cin>>nf>>ne;

    cout<<min_trials_in_worst_case(nf, ne)<<endl;

    return 0;
}
