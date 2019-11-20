#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

//bool compare(string a, string b){
//    return a>b;
//}
bool compare(string a, string b){
    return a.length()>b.length();
}


int main(){
    string s("Hello World");
    cout<<s<<endl;

    string s2 = "Another Way!";
    cout<<s2<<endl;

    cout<<s2.length()<<endl;
    for(int j=0; j<s2.length(); j++){
        cout<<s2[j]<<"-";
    }
    cout<<endl;
    string s3;
    getline(cin, s3);
    cout<<s3<<endl;

    string arr[]  = {"Pineapple", "Apple", "Mango", "Guava", "Watermelon"};
//    sort(arr, arr+4);
    sort(arr, arr+5, compare);
    for(int i=0; i<5; i++){
        cout<<arr[i]<<", ";
    }
    return 0;
}
