#include<iostream>
using namespace std;

char bete_max_freq_char_batao(string str){
    int i=0;
    int freq[26]={0};
    while(str[i]!='\0'){
        freq[str[i]-'a']++;
        i++;
    }
    int max=0;
    i=0;
    while(i<25){
        if(freq[i]>freq[max]){
            max = i;
        }
        i++;
    }
    max = max + 'a';
    return (char)max;
}

int main(){
    string str;
    cin>>str;

    cout<<bete_max_freq_char_batao(str)<<endl;

    return 0;
}
