#include<iostream>
#include<stack>
using namespace std;

void insert_at_bottom(stack<int> &s, int data){
    if(s.empty()){
        s.push(data);
        return;
    }
    int temp = s.top();
    s.pop();
    insert_at_bottom(s, data);
    s.push(temp);
    return;
}

void recursive_reverse(stack<int> &s){
    if(s.empty()){
        return;
    }

    int temp = s.top();
    s.pop();
    recursive_reverse(s);
    insert_at_bottom(s, temp);
    return;
}

void print_stack(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}

int main(){
    stack<int> s;
    int n;
    cin>>n;
    int temp;
    while(n--){
        cin>>temp;
        s.push(temp);
    }

    recursive_reverse(s);
    print_stack(s);
    return 0;
}
