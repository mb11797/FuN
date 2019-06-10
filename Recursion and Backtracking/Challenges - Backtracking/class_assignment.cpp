#include<iostream>
using namespace std;

int count_integers(int n, string osf, int i){
    if(i==n){
        cout<<osf<<" ";
        return 1;
    }

    int cnt = 0;

    if(osf[i-1]=='b'){
        cnt += count_integers(n, osf+"a", i+1);
    }
    else if(osf[i-1]!='b'){
        cnt += count_integers(n, osf+"a", i+1);
        cnt += count_integers(n, osf+"b", i+1);
    }
    return cnt;
}

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n;
        cin>>n;

        int ans = count_integers(n, "", 0);
        cout<<endl;
        cout<<"#"<<n<<" : "<<ans<<endl;
    }
    return 0;
}
