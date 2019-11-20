#include<iostream>
#include<stack>
using namespace std;

bool check_redundant_parenthesis(string str){
    stack<char> s;

    for(int i=0; str[i]!='\0'; i++){
        char curr = str[i];
        if(curr != ')'){
            s.push(curr);
        }
        else if(curr == ')'){
            if(s.top()=='(')
                return true;
            while(s.top()!='('){
                s.pop();
                if(s.empty())
                    return true;
            }
            s.pop();
        }
    }
    return false;
}

int main(){
    string str;
    cin>>str;

    if(check_redundant_parenthesis(str))
        cout<<"Duplicate"<<endl;
    else
        cout<<"Not Duplicates"<<endl;
    return 0;
}
