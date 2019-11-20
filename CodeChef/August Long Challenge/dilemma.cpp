#include<iostream>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    string str;
    int count;
    while(tc--){
        cin>>str;
        int count=0;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='1'){
                count++;
            }
        }

        if(count%2==0){
            cout<<"LOSE"<<endl;
        }
        else{
            cout<<"WIN"<<endl;
        }

    }

    return 0;
}
