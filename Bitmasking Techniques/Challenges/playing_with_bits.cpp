#include<iostream>
using namespace std;

int count_set_bits(int*range){

	int tot = 0;

	for(int no=range[0]; no<=range[1]; no++){
		int n = no;
		while(n>0){
			n = (n & (n - 1));
			tot++;
		}

	}
	return tot;
}

int main(){
	int Q;
	cin>>Q;

	int range[Q][2];

	for(int i=0; i<Q; i++){
		for(int j=0; j<2; j++){
			cin>>range[i][j];
		}
	}


	for(int i=0; i<Q; i++){
		cout<<count_set_bits(range[i])<<endl;
	}

	return 0;
}