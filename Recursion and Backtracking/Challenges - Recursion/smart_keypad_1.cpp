#include<iostream>
using namespace std;

//char keypad[][10] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wx", "yz"};
string keypad[] = { " ", ".+@$", "abc", "def", "ghi", "jkl" , "mno", "pqrs" , "tuv", "wxyz" };

void print_keypad_string_codes(char*in, char*out, int i, int j){
    if(in[i]=='\0'){
        out[j] = '\0';
        cout<<out<<"\n";
        return;
    }

    int digit = in[i] - '0';

//    if(digit==0){
//        out[i] = ' ';             //use only if (keypad[0]="") and not when (keypad[0]=" ")
//        print_keypad_string_codes(in, out, i+1, j+1);
//    }
    for(int kp=0; keypad[digit][kp] != '\0'; kp++){
        out[j] = keypad[digit][kp];
        print_keypad_string_codes(in, out, i+1, j+1);
    }
    return;
}

int main(){
    char in[100];
    cin>>in;

    char out[100];
    print_keypad_string_codes(in, out, 0, 0);
    cout<<endl;

    return 0;
}

