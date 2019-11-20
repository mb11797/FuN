#include<iostream>
#include<vector>
using namespace std;

#define ll long long

bool v[100000005];
vector<int> prime_vector;
void sieve(){
    for(ll i=2; i<100000005; i+=2){
        v[i] = true;
    }
    prime_vector.push_back(2);
    for(ll i=3; i<100000005; i+=2){
        if(!v[i]){
            prime_vector.push_back(i);
            for(int j=i; (j*i)<100000005; j+=2){
                if(!v[j*i])
                    v[j*i] = true;
            }
        }
    }

}

int main(){
    int t;
    cin>>t;

    int n;

    sieve();
    while(t--){
        cin>>n;
        n--;
        cout<<prime_vector[n]<<endl;
    }
    return 0;
}
