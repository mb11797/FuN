#include<iostream>
#include<cstring>
using namespace std;

int main(){
//    char str[] = "abshabsjakelm";
//    char str[] = "abcdeabhgjklio";
    char str[] = "abcdecde";
    int max_len = 1;
    int current_len = 1;
    int n = strlen(str);
    int visited[256];
    for(int i=0; i<256; i++){
        visited[i] = -1;
    }
    visited[str[0]] = 0;

    for(int i=1; i<n; i++){
        int last_occ =  visited[str[i]];

        if(last_occ==-1 || i-current_len>last_occ){
            current_len++;
            max_len = max(current_len, max_len);
        }
        else{
            if(current_len>max_len){
                max_len = current_len;
            }
            current_len = i-last_occ;
        }
        visited[str[i]] = i;
    }

    cout<<max_len<<endl;
    return 0;
}
