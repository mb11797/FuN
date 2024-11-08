#include<iostream>
using namespace std;

void subsequences(char*in, char*out, int i, int j){
    //base case
    if(in[i]=='\0'){
        out[j] = '\0';
        cout<<out<<endl;
        return;
    }

    //Recursion
    //1. Include the current character
    out[j] = in[i];
    subsequences(in, out, i+1, j+1);

    //2. Exclude the current character (it will be overwritten by some other character as j is not increased)
    subsequences(in, out, i+1, j);


    return;
}

int main(){
    char in[100];
    cin>>in;

    char out[100];

    subsequences(in, out, 0, 0);
    return 0;
}
