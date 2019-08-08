#include<iostream>
using namespace std;

int no_of_triplets(int*a, int n, int s, int e){
    if(s>e)
        return 0;

    int xor_res=0;
    for(int i=s; i<e; i++){
        xor_res = xor_res ^ a[i];
    }
    int count=0;
    if(xor_res != 0){
        count += no_of_triplets(a, n, s+1, e);
        count += no_of_triplets(a, n, s, e-1);
    }
    else if(xor_res == 0){
        for(int i=s; i<e; i++){

        }
    }


    return count;
}

int main(){
    int tc;
    cin>>tc;

    int n;

    while(tc--){
        cin>>n;
        int a[n];
        for(int i=0; i<n; i++){
            cin>>a[i];
        }

        cout<<no_of_triplets(a, n, 0, n-1)<<endl;

    }
    return 0;
}
