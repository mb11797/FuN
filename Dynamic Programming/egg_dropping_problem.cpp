#include<iostream>
using namespace std;

int min_trials_in_worst_case(int nf, int ne){
    if(ne == 1){
        return nf;
    }



    return 0;
}

int main(){
    int nf, ne;
    cin>>nf>>ne;

    cout<<min_trials_in_worst_case(nf, ne)<<endl;

    return 0;
}
