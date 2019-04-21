#include<iostream>
using namespace std;

int power_using_bitwise(int a, int b){
	int res = 1;
	int p=a;
	while(b>0){
		(b&1) ? res*=p : res*=1;
		p *= p;
		b = (b>>1);
	}
	return res;
}

int main(){
	int n, p;
	cin>>n>>p;

	cout<<power_using_bitwise(n, p)<<endl;

	return 0;
}