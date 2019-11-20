#include <bits/stdc++.h>
using namespace std;

long printSubstrings(string s){
    unordered_set<string> u_s;
    for (int i = 0; i < s.size(); ++i) {
        string ss = "";
        for (int j = i; j < s.size(); ++j) {

            ss = ss + s[j];
            u_s.insert(ss);
        }
    }

    return u_s.size();
}

// Driver code
int main()
{
    string str = "kincenvizh";
    cout<<printSubstrings(str)<<endl;
    return 0;
}
