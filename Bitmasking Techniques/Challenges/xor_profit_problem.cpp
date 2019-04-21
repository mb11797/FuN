#include<iostream>
using namespace std;

int max_valued_xor(int x, int y){
	int mx=0;
	for(int a=x; a<=y; a++){
		for(int b=a; b<=y; b++){
			mx = max(mx, a^b);
		}
	}
	return mx;
}

int main(){
	int x, y;
	cin>>x>>y;

	cout<<max_valued_xor(x, y)<<endl;

	return 0;
}