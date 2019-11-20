#include<iostream>
#include<cstring>
using namespace std;

int search_char(char ch, string S1){
    int l1 = S1.length();
    int i;
    for(i=0; i<l1; i++){
        if(S1[i]==ch)
            break;
    }
    return i;
}

int solution(string &S1, string &S2) {
    // write your code in C++14 (g++ 6.2.0)
//    cout<<S1[0]<<endl;
    int l1, l2;
    l1 = S1.length();
    l2 = S2.length();
    cout<<l1<<" "<<l2<<"\n";
    int c_index=0;
    int time=0;
    for(int i=0; i<l2; i++){
        int finger_index = search_char(S2[i], S1);
        time = time + abs(finger_index - c_index);
        c_index = finger_index;
    }
    return time;
}

int main(){
    string s1;
    string s2;

    cin>>s1;
    cin>>s2;

    cout<<endl;
    int time = solution(s1, s2);
    cout<<time<<endl;
    return 0;
}
