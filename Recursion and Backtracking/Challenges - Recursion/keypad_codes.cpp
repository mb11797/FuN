#include<iostream>
using namespace std;

char keypad[][10] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};

void print_keypad_string_codes(char*in, char*out, int i, int j, int *count){
    if(in[i]=='\0'){
        *count += 1;
        out[j] = '\0';
        cout<<out<<" ";
        return;
    }

    int digit = in[i] - '0';
    digit = digit - 1;              //as 0 is not there in the keypad
    for(int kp=0; keypad[digit][kp] != '\0'; kp++){
        out[j] = keypad[digit][kp];
        print_keypad_string_codes(in, out, i+1, j+1, count);
    }
    return;
}

int main(){
    char in[100];
    cin>>in;

    char out[100];
    int count = 0;
    print_keypad_string_codes(in, out, 0, 0, &count);
    cout<<endl;
    cout<<count<<endl;
    return 0;
}
