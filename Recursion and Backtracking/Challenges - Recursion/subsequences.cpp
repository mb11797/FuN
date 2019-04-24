#include<iostream>
#include<string>
using namespace std;

int generate_subsequences(string str, string osf, int count){
    if(str==""){
        cout<<osf<<" ";
        count++;
        return count;
    }
    //rec case
    char ch = str[0];
    string ros = str.substr(1);
    count += generate_subsequences(ros, osf, count) + generate_subsequences(ros, osf+ch, count);
    return count;
}

int main(){
    string str;
    cin>>str;

    int count = generate_subsequences(str, "", 0);
    cout<<endl<<count<<endl;

    return 0;
}
