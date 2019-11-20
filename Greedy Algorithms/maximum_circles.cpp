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
    int c[] = {1,2,3,4};
    int r[] = {1,1,1,1};

    int n = sizeof(c)/sizeof(int);

    int m_c = maximum_non_overlapping_circles(c, r, n);

    cout<<"Maximum circles selected: "<<m_c<<endl;
    cout<<"Circles removed: "<<n-m_c;
    return 0;
}
