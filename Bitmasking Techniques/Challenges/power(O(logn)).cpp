#include<iostream>
#include<math.h>
using namespace std;

int power(int x, int n){
	if(n==1)
		return x;
	if(n==0)
		return 1;
	if(x==1)
		return 1;
	if(n%2==0)
		return pow(power(x, n/2), 2);
	else
		return x*pow(power(x, (n-1)/2), 2);
}

int main(){

	int x, n;
	cin>>x>>n;
	cout<<power(x, n)<<endl;
	return 0;
}