#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<string> s;

    s.push("Apple");
    s.push("Watermelon");
    s.push("Guava");
    s.push("Orange");

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }

    return 0;
}
