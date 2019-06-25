#include<iostream>
#include<algorithm>
using namespace std;

bool comparator(pair<int, int> p1, pair<int, int> p2){
    return (p1.second < p2.second);
}

void print_max_activity_selection(pair<int, int> p[], int n){
    sort(p, p+n, comparator);

    int i=0;
    cout<<i<<"- ("<<p[i].first<<", "<<p[i].second<<")"<<endl;

    for(int j=1; j<n; j++){
        if(p[j].first>p[i].second){
            cout<<j<<"- ("<<p[j].first<<", "<<p[j].second<<")"<<endl;
            i=j;
        }
    }
    return;
}

int main(){
    pair<int, int> p[] = {{5,9}, {0,2}, {3,4}, {0,6}, {5,7}, {8,9}};
    int n = sizeof(p)/sizeof(p[0]);

    print_max_activity_selection(p, n);
    return 0;
}
