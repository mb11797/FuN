#include<iostream>
#include<vector>
using namespace std;
int a[10000000]={0};
vector<bool>isPrime (10000000,true);
void prime(){
    // a[0] = a[1] = 0;
    // a[2] = 1;

    // for(int i=3;i<=10000;i+=2){
    //     a[i] = 1;
    // }

    // for(int i=3;i<=10000;i+=2){
    //     if(a[i]){
    //         for(int j = i*i; j<=10000; j+=2*i){
    //             a[j] = 0;
    //         }
    //     }
    // }
    // return;
    isPrime[0]=isPrime[1]=false;
    for(int i=2;i*i<=10000000;i++){
        if(isPrime[i]){
            for(int j=i;j*i<=10000000;j++) isPrime[i*j]=false;
        }
    }
    int idx = 1;
    a[0]=2;

    for(int i=3;i<=10000000;i+=2){
        if(isPrime[i]){
            a[idx++]=i;
        }
    }
}



void check(int n){

   // int p[n];
    vector<int> v;

    for(int i=2;i<=10000;i++){
    if(a[i]){
        v.push_back(i);
         }

    }
    cout<<v[n-1]<<'\n';


}
int main() {
    int test;
     prime();
    cin>>test;
    while(test--){
        int n;
        cin>>n;
        // check(n);
        cout<<a[n-1]<<endl;
    }
	return 0;
}
