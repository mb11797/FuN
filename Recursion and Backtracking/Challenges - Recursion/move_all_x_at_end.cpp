#include<iostream>
using namespace std;

void move_all_x_at_end(char*str, int i, string osf, string all_x){
    if(str[i]=='\0'){
        osf += all_x;
        cout<<osf<<endl;
        return;
    }

    if(str[i]=='x'){
        move_all_x_at_end(str, i+1, osf, all_x+'x');
    }
    else{
        move_all_x_at_end(str, i+1, osf+str[i], all_x);
    }
    return;
}

int main(){
    char str[100];
    cin>>str;

    move_all_x_at_end(str, 0, "", "");
    return 0;
}
