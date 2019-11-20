#include<iostream>
#include<algorithm>
using namespace std;

void tricky_permute(char*str, int i, string temp[], int &k){
    if(str[i]=='\0'){
        temp[k] = str;
        k++;
        return;
    }
    for(int j=i; str[j]!='\0'; j++){
        if(j!=i && str[j]==str[i]){
        }
        else{
            swap(str[i], str[j]);
            tricky_permute(str, i+1, temp, k);
            //backtracking
            swap(str[i], str[j]);
        }
    }
    return;
}

int main(){
    char str[1000];
    cin>>str;

    int k = 0;
    string temp[10000];
    tricky_permute(str, 0, temp, k);

    string s[10000];
    int r = 0;
    for(int i=0; i<k; i++){
        int flag=0;
        for(int j=i+1; j<k; j++){
            if(temp[i]==temp[j]){
                flag = 1;
            }
        }
        if(flag==0){
            s[r] = temp[i];
            r++;
        }
    }

    sort(s, s+r);

    for(int i=0; i<r; i++)
        cout<<s[i]<<endl;

    return 0;
}
