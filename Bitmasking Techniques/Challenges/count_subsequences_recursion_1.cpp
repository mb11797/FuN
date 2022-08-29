#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void subse(string str,string osf,string* strk,int &c){
    if(str.length()==0){
        strk[c] = osf;
        c++;
        return ;
    }
    char a = str[0];
    string ros = str.substr(1);
    subse(ros,osf,strk,c);
    subse(ros,osf + a,strk,c);
    return;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        string str;
        cin>>str;
        string strk[100000];
        int c = 0;
        subse(str,"",strk,c);
        sort(strk,strk+c);
        int ac_count = 1;
        for(int j=0;j<c;j++){
            if(strk[j]==strk[j-1]){
                continue;
            }
            else{
                ac_count+=1;
            }
        }
        cout<<ac_count<<"\n";
    }
    return 0;
}
