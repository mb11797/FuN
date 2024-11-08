#include<iostream>
#include<cstring>
using namespace std;

int arr[100];
int n;
int memo[100][100];

int max_score_of_Modi_ji(int be, int en){
    if(be > en){
        return 0;
    }

    if(be == en+1){
        return max(arr[be], arr[en]);
    }

    if(memo[be][en] != -1){
        return memo[be][en];
    }

    int modi_pick_beg = arr[be] + min(max_score_of_Modi_ji(be+2, en), max_score_of_Modi_ji(be+1, en-1));
    int modi_pick_end = arr[en] + min(max_score_of_Modi_ji(be+1, en-1), max_score_of_Modi_ji(be, en-2));

    return memo[be][en] = max(modi_pick_beg, modi_pick_end);
}

int main(){
    memset(memo, -1, sizeof(memo));
    cin>>n;

    int total_sum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        total_sum += arr[i];
    }

    int Modi = max_score_of_Modi_ji(0, n-1);
    int Trump = total_sum - Modi;

    cout<<"Modi's score: "<<Modi<<endl;
    cout<<"Trump's score: "<<Trump<<endl;
    cout<<"Modi wins by "<<Modi - Trump<<" point margin."<<endl;

    return 0;
}
