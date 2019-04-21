#include<iostream>
using namespace std;

void print_unique_no(int*arr, int n){

	int res=0;
	for(int i=0; i<n; i++){
		res ^= arr[i];
	}
	cout<<res<<endl;
}

int main(){
	int n;
	cin>>n;
	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	print_unique_no(arr, n);

	return 0;
}