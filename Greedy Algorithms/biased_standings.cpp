#include<iostream>
#include<cstdlib>
using namespace std;

// badness = |actual_rank - preferrred_rank|

typedef pair<string, int> pr;

int find_min_total_badness(pr p[], int n){
    int mx = p[0].second;
    for(int i=0; i<n; i++){
        if(p[i].second > mx){
            mx = p[i].second;
        }
    }

    int freq[mx+1] = {0};

    for(int i=0; i<n; i++){
        freq[p[i].second]++;
    }

    int pos = 1;
    int min_badness = 0;
    for(int i=0; i<=mx; i++){
        while(freq[i]){
            min_badness += abs(pos - i);
            freq[i]--;
            pos++;
        }
    }
    return min_badness;
}

int main(){
    pr p[] = {{"noobz", 1}, {"llamas", 2}, {"Winn3rz", 2}, {"5thwheel", 1}, {"NotoricCoders", 5}, {"StrangeCase", 7}, {"WhoKnows", 7}};

    int n = sizeof(p)/sizeof(p[0]);
    for(int i=0; i<n; i++)
        cout<<p[i].first<<" "<<p[i].second<<endl;

    cout<<find_min_total_badness(p, n);
    return 0;
}
