#include<iostream>
using namespace std;

void replace_all_pi(char*str, string osf){
    if(str[0]=='\0'){
        cout<<osf<<endl;
        return;
    }

    if(str[0]=='p'){
        if(str[1]=='i')
            replace_all_pi(str+2, osf+"3.14");
        else
            replace_all_pi(str+1, osf+str[0]);
    }
    else{
        replace_all_pi(str+1, osf+str[0]);
    }
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        char str[1000];
        cin>>str;


        replace_all_pi(str, "");
    }
    return 0;
}
