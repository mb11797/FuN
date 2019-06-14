#include<iostream>
using namespace std;

#define ll long long

ll cntSubStrings(ll n)
{
	ll ends_1[100], ends_0[100];
	ends_0[1] = ends_1[1] = 1;

	for(ll i=2;i<=n;i++)
	{
		ends_1[i] = ends_1[i-1] + ends_0[i-1];
		ends_0[i] = ends_1[i-1];
	}

	return ends_1[n] + ends_0[n];
}

int main() {
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<cntSubStrings(n)<<endl;
	}
	return 0;
}
