#include<iostream>
#include<algorithm>
#include<cmath>             //for abs()
using namespace std;

bool myComparator(int a, int b){
    return a>b;
}

int minimum_imbalance(int spec_mass[], int c, int s){
    int total_mass=0;
    for(int i=0; i<s; i++)
        total_mass += spec_mass[i];
    int avg_mass = total_mass / c;
    cout<<avg_mass<<endl;

    sort(spec_mass, spec_mass+s, myComparator);         //sorting all specimen masses in decreasing order leaving the zeros at the end


    for(int i=0; i<2*c; i++)
        cout<<spec_mass[i]<<" ";

    cout<<endl;


    int min_imbalance = 0;
    for(int i=0; i<c; i++){
        int chamber_mass = spec_mass[i] + spec_mass[2*c-i-1];
        min_imbalance += abs(chamber_mass - avg_mass);
    }

    return min_imbalance;
}

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int nc;
        cin>>nc;

        int ns;
        cin>>ns;

        int spec_mass[2 * nc] = {0};
        for(int i=0; i<ns; i++)
            cin>>spec_mass[i];


        cout<<minimum_imbalance(spec_mass, nc, ns)<<endl;
    }

    return 0;
}
