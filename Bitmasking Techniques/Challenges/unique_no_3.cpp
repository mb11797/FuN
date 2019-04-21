#include<iostream>
using namespace std;

void print_unique_no(int*arr, int n){
	int cnt[64]={0};

	//taking the sume of every bit of each no in array cnt
	int mx=0;
	for(int i=0; i<n; i++){

		int no = arr[i];
		int j=0;
		while(no>0){
			cnt[j] += (no & 1);
			no = (no >> 1);
			j++;
			mx = max(j, mx);
		}
	}

	int u_no = 0;
	int p = 1;
	for(int j=0; j<mx; j++){
		cnt[j] %= 3;

		u_no += cnt[j] * p;
		p = (p<<1); 
	}

	cout<<u_no<<endl;
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