#include<iostream>
using namespace std;

void print_unique_nos(int*arr, int n){
	int res=0;
	for(int i=0; i<n; i++){
		res ^= arr[i];
	}

	int i=0;
	int temp = res;
	while(temp>0){
		if(temp&1)
			break;
		temp = (temp>>1);
		i++;
	}

	int mask= (1<<i);
	int first_no = 0;
	for(int i=0; i<n; i++){
		if(mask & arr[i]){
			first_no ^= arr[i];
		}
	}

	int second_no = res^first_no;
	cout<<first_no<<endl;
	cout<<second_no<<endl;
}

int main(){
	int n;
	cin>>n;

	int arr[n];
	for(int i=0; i<n; i++){
		cin>>arr[i];
	}

	print_unique_nos(arr, n);

	return 0;
}