#include<bits/stdc++.h>
using namespace std;


int subString_calculator(string s, int n){
    set<string> st;
    int count =0;
    for (int i = 0; i < n; i++)
        for (int len = 1; len <= n - i; len++){
            st.insert(s.substr(i, len));
            cout << s.substr(i, len) << endl;
            count++;
        }
    return st.size();
}


int main()
{
    string s = "kincenvizh";
//    string s = "abcde";
    cout<<subString_calculator(s,s.length())<<endl;;
    return 0;
}
