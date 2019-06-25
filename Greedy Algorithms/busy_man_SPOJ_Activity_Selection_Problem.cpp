#include<iostream>
using namespace std;

void select_max_activities(int s[], int f[], int n){
    int i=0;
    cout<<i<<" ";

    for(int j=1; j<n; j++){
        if(s[j]>=f[i]){
            cout<<j<<" ";
            i=j;
        }
    }
}

int main(){
    int s[] = {1,3,0,5,8,5};
    int f[] = {2,4,6,7,9,9};

    int n = sizeof(s)/sizeof(int);

    select_max_activities(s, f, n);
    return 0;
}






