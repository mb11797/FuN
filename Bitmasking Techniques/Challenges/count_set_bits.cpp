#include<iostream>
using namespace std;

int count_set_bits(int n){
	int cnt=0;
	while(n){
		n = (n & n-1);
		cnt++;
	}
	return cnt;
}

int main(){
	int tc;
	cin>>tc;
	int arr[tc];
	for(int i=0; i<tc; i++){
		cin>>arr[i];
	}

	int i=0;
	while(tc>0){
		cout<<count_set_bits(arr[i])<<endl;
		i++;
		tc--;
	}

	return 0;
}