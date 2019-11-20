#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

//int count_dig(int no){
//    int cnt=0;
//    while(no/10!=0){
//        no = no/10;
//        cnt++;
//    }
//    return cnt;
//}

int myCompare(string X, string Y){
    string XY = X.append(Y);
    string YX = Y.append(X);

    return XY.compare(YX)>0?1:0;
}

void printLargest(vector<string> ar){
    sort(ar.begin(), ar.end(), myCompare);
    for(int i=0; i<ar.size(); i++){
        cout<<ar[i];
    }
    cout<<endl;
}

int main(){
    int tc;
    cin>>tc;
    int i=0;
    while(i<tc){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    vector<string> ar;
    for(int i=0; i<n; i++){
        ar.push_back(to_string(arr[i]));
    }

    printLargest(ar);
    i++;
    }
    return 0;
}
