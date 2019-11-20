#include<iostream>
using namespace std;

int count_integers(int n){
    int a[n+1],b[n+1];
    a[0] = b[0] = 1;
    for(int i=1;i<n;i++){
        a[i]=a[i-1]+b[i-1];
        b[i]=a[i-1];
    }
    return a[n-1]+b[n-1];
}

int main(){
    int tc;
    cin>>tc;

	int i=0;
    while(i<tc){
        int n;
        cin>>n;

        cout<<"#"<<i+1<<" : "<<count_integers(n)<<endl;
		i++;
	}
    return 0;
}

