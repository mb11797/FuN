#include <bits/stdc++.h>
#include <sstream>
using namespace std;
string ss[10000];
int ind=0;
void PermutationLexo(string s,string check, int be,int en){

    if(be>en){
            if(s<check){
                ss[ind]=s;ind++;
            }
    }
    for(int i=be;i<=en;i++){
        swap(s[i],s[be]);
        PermutationLexo(s,check,be+1,en);\
        // swap(s[i], s[be]);
    }
}
int main()
{
    string s;cin>>s;
    PermutationLexo(s,s,0,s.size()-1);
    for(int i=0;i<ind;i++){
        cout<<ss[i]<<endl;
    }
    return 0;
}

