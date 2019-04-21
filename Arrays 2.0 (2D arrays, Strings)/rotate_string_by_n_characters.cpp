#include<iostream>
#include<cstring>
using namespace std;

void rotate(char*a, int k){
    int i = strlen(a);
    while(i>=0){
        a[i+k] = a[i];
        i--;
    }
    cout<<a<<endl;

    i = strlen(a);
    cout<<i<<endl;

    int s=0;
    int j=i-k;
    while(j<i){
        a[s] = a[j];
        s++;
        j++;
    }
    a[i-k] = '\0';
}

int main(){
    char a[100] = "Coding Blocks";
    int k=6;
    rotate(a, k);

    cout<<a<<endl;
    return 0;
}


