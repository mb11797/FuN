#include<iostream>
using namespace std;

int count_integers(int n){
    int a[n+1],b[n+1];
    a[0]=0,a[1]=1;
    b[0]=0,b[1]=1;
    for(int i=2;i<=n;i++){
        a[i]=a[i-1]+b[i-1];
        b[i]=a[i-1];
    }
    return a[n]+b[n];
}

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n;
        cin>>n;

        int ans = count_integers(n);
        cout<<endl;
        cout<<"#"<<n<<" : "<<ans<<endl;
    }
    return 0;
}

