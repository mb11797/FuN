#include<iostream>
using namespace std;

int main() {
    int tc;
    cin>>tc;

    int arr[tc];
    for(int i=0; i<tc; i++){
    	cin>>arr[i];
    }
    int i=0;
    while(tc>0){
 		int n = arr[i];
    	int min_steps = 0;
 		while(n){
 			n = (n & (n-1));
 			min_steps++;
 		}
 		cout<<min_steps<<endl;
 		i++;
        tc--;
    }
	return 0;
}