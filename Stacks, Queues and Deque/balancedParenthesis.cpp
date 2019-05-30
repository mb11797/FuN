#include<iostream>
#include<stack>
using namespace std;

bool checkBalanced(string str){
    stack<char> s;
    int i=0;
    while(str[i]!='\0'){
        if(str[i]=='('){
            s.push(str[i]);
        }
        else if(str[i]==')'){
            if(!s.empty())
                s.pop();
            else
                return false;
        }
        i++;
    }
    return s.empty();
}

int main(){
    string str;
    cin>>str;

    if(checkBalanced(str))
        cout<<"Balanced"<<endl;
    else
        cout<<"Not balanced"<<endl;

    return 0;
}
