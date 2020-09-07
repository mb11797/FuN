#include<iostream>
#include<stack>
using namespace std;

void stock_span(int*stock, int n){
    stack<int> s;
    int ans[n] = {};

    for(int day = 0; day<n; day++){
        int currPrice = stock[day];

        while(!s.empty() && currPrice > stock[s.top()]){
            s.pop();
        }
        int betterDay = s.empty()? 0 : s.top();
        int span = day - betterDay;
        ans[day] = span;
        s.push(day);
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int n = 7;
    int stock[] = {100, 80, 60, 70, 60, 75, 85};

    stock_span(stock, n);
    return 0;
}
