#include<iostream>
#include<stack>
using namespace std;

void transfer(stack<int> &s1, stack<int> &s2, int n){
    for(int i=0; i<n; i++){
        s2.push(s1.top());
        s1.pop();
    }
}

void reverse_stack(stack<int> &s1){
    stack<int> s2;
    int n = s1.size();
    for(int i=0; i<n-1;i++){
        int temp = s1.top();
        s1.pop();
        transfer(s1, s2, n-1-i);
        s1.push(temp);
        transfer(s2, s1, n-1-i);
    }
}

int main(){
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

//    while(s.empty() == 0){
//        cout<<s.top()<<"<-";
//        s.pop();
//    }
//    cout<<endl;
//
//    s.push(1);
//    s.push(2);
//    s.push(3);
//    s.push(4);

    reverse_stack(s);

    while(s.empty() == 0){
        cout<<s.top()<<"<-";
        s.pop();
    }
    return 0;
}
