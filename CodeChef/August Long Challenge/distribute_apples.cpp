#include<iostream>
using namespace std;

int find_min_box_idx(int*box, int k){
    int min_val = INT_MAX;
    int min_idx = -1;
    for(int i=0; i<k; i++){
        if(box[i] < min_val){
            min_val = box[i];
            min_idx = i;
        }
    }
    return min_idx;
}

bool different_distribution(int n, int k){
    int box_cand1[k] = {0};
    int box_cand2[k] = {0};

    //candidate 1 style filling
    for(int i=0; i<n/k; i++){
        for(int j=0; j<k; j++){
            box_cand1[j] += 1;
        }
    }

    //candidate 2 style filling
    while(n>0){
        int min_box_idx = find_min_box_idx(box_cand2, k);

        if(n > k){
            box_cand2[min_box_idx] += k;
            n -= k;
        }
        else{
            box_cand2[min_box_idx] += n;
            n -= n;
        }
    }

    for(int i=0; i<k; i++){
        if(box_cand1[i] != box_cand2[i])
            return true;
    }
    return false;
}


int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n, k;
        cin>>n>>k;

        if(different_distribution(n, k))
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;

    }

    return 0;
}
