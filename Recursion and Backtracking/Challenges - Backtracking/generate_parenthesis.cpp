#include<iostream>
using namespace std;

void generate_parenthesis(int n, string osf, int open, int close){
    if(close<open)
        generate_parenthesis(n, osf+")", open, close+1);

    if(close>=n){
        cout<<osf<<endl;
        return;
    }
    if(open<n)
        generate_parenthesis(n, osf+"(", open+1, close);

}

int main(){
    int n;
    cin>>n;

    generate_parenthesis(n, "", 0, 0);
    return 0;
}
