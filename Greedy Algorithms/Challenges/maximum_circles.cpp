#include<iostream>
#include<algorithm>
using namespace std;

typedef pair<int, int> pr;

bool myComparator(pr p1, pr p2){
    return p1.second < p2.second;
}

int maximum_non_overlapping_circles(int c[], int r[], int n){
    pr p[n];
    for(int i=0; i<n; i++){
        p[i].first = c[i] - r[i];
        p[i].second = c[i] + r[i];
    }

    sort(p, p+n, myComparator);

    int noc = 0;
    int j=0;
    noc++;
    for(int k=1; k<n; k++){
        if(p[k].first >= p[j].second){
            noc++;
            j = k;
        }
    }
    return noc;
}

int main(){
    int n;
    cin>>n;

    int c[n], r[n];
    for(int i=0; i<n; i++)
        cin>>c[i]>>r[i];

    int mx_noc = maximum_non_overlapping_circles(c, r, n);
    int n_remove = n - mx_noc;
    cout<<n_remove<<endl;;

    return 0;
}
