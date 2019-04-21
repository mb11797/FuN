#include<iostream>
#include<cstring>
using namespace std;

#define ll long long

ll arr[1000005], freq[1000005];

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int n;
        cin>>n;

        memset(freq, 0, sizeof freq);

        freq[0] = 1;

        ll sum=0;
        for(int i=0; i<n; i++){
            cin>>arr[i];
            sum += arr[i];
            sum %= n;
            sum = (sum+n)%n;
            freq[sum]++;
        }

        ll ans = 0;
        for(int i=0; i<n; i++){
            ll no = freq[i];
            ans += (no * (no - 1)) / 2;
        }

        cout<<ans<<endl;
    }
    return 0;
}
