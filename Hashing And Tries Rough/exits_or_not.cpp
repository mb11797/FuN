#include<iostream>
#include<unordered_map>

using namespace std;

#define ll long long

int main() {

    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        unordered_map<ll,bool> m;
        ll num;
        for(ll i=0;i<n;i++){
            cin >> num;
            m[num] = true;
        }

        ll q;
        cin >> q;
        while(q-- && q>-1){
            cin >> num;
            if(m[num]==true){
                cout << "Yes" << endl;
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }

	return 0;
}
