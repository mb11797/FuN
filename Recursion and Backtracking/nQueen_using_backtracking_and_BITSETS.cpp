#include<iostream>
#include<bitset>
using namespace std;

bitset<30> col, diag_1, diag_2;

void search_configuration(int r, int n, int &ans){
    if(r==n){
        ans++;
        return;
    }

    for(int c=0; c<n; c++){
        if(!col[c] && !diag_1[r-c+n-1] && !diag_2[r+c]){
            col[c] = diag_1[r-c+n-1] = diag_2[r+c] = 1;
            search_configuration(r+1, n, ans);
            col[c] = diag_1[r-c+n-1] = diag_2[r+c] = 0;
        }
    }
    return;
}

int main(){
    int n;
    cin>>n;

    int ans = 0;
    search_configuration(0, n, ans);
    cout<<ans<<endl;

    return 0;
}
