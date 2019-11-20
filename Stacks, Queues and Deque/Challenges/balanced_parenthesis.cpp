#include<iostream>
#include<stack>
using namespace std;

bool is_balanced(string str){
    stack<char> s;

    for(int i=0; str[i]!='\0'; i++){
        if(str[i] == '(')
            s.push(str[i]);
        else if(str[i] == ')'){
            if(!s.empty() and s.top()=='(')
                s.pop();
            else
                return false;
        }
        else if(str[i] == '{')
            s.push(str[i]);
        else if(str[i] == '}'){
            if(!s.empty() and s.top()=='{')
                s.pop();
            else
                return false;
        }
        else if(str[i] == '[')
            s.push(str[i]);
        else if(str[i] == ']'){
            if(!s.empty() and s.top()=='[')
                s.pop();
            else
                return false;
        }
    }

    if(!s.empty())
        return false;
    else
        return true;
}

int main(){
    string str;
    cin>>str;

    if(is_balanced(str))
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    return 0;
}
