#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom(stack<int>&s, int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int temp = s.top();
    s.pop();
    insert_at_bottom(s, x);
    s.push(temp);
}

void reverse_stack_rec(stack<int>& s){
    if(s.empty()){
        return;
    }
    int temp = s.top();
    s.pop();
    reverse_stack_rec(s);
    insert_at_bottom(s, temp);
}

int main(){
    stack<int> s;
    int temp;
    cin>>temp;
    while(temp!=-1){
        s.push(temp);
        cin>>temp;
    }

    reverse_stack_rec(s);

    while(!s.empty()){
        cout<<s.top()<<"<-";
        s.pop();
    }
    return 0;
}
