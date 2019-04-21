#include<iostream>
#include<cstring>
using namespace std;

#define ll long long

ll a[1000005], prefixSum[1000005];

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        ll sum=0;
        memset(prefixSum, 0, sizeof prefixSum);

        prefixSum[0] = 1;

        for(int i=0; i<n; i++){
            cin>>a[i];
            cout<<"Sum = "<<sum<<endl;
            sum += a[i];
            sum %= n;
            sum = (sum+n)%n;
            //first make the no positive (case added due to negative nos)
            //then update the frequency
            cout<<"Sum = "<<sum<<endl;

            prefixSum[sum]++;
        }

        ll ans = 0;
        for(int i=0; i<n; i++){
            cout<<prefixSum[i]<<endl;
            ll no = prefixSum[i];
            ans += (no*(no - 1))/2;
        }
        cout<<"Ans = "<<ans<<endl;
    }

    return 0;
}
