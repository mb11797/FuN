#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void subseq(string str, string osf, string*strk, int &c){
    if(str.length()==0){
        strk[c] = osf;
        c++;
        return;
    }

    char ch = str[0];
    string ros = str.substr(1);
    subseq(ros, osf, strk, c);
    subseq(ros, osf+ch, strk, c);
    return;
}

int main(){
    int t;
    cin>>t;

    for(int i=0; i<t; i++){
        string str;
        cin>>str;
        string strk[10000];                 //array of strings
        int c=0;
        subseq(str, "", strk, c);
        sort(strk, strk+c);
        int count = 1;
        for(int j=1; j<c; j++){
            if(strk[j]==strk[j-1]){
                continue;
            }
            else{
                count+=1;
            }
        }
        cout<<count<<endl;
    }
    return 0;
}

