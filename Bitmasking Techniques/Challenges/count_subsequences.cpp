#include<iostream>
#include<cstring>
using namespace std;

// void filterChars(string str, int no){
// 	int i=0;
// 	while(no>0){
// 		(no & 1) ? cout<<str[i] : cout<<"";
// 		no = (no>>1);
// 		i++;
// 	}

// }

// void generate_subsets(string str){
// 	int len = strlen(str);
// 	int range = (1<<len)-1;

// 	for(int i=0; i<=range; i++){
// 		filterChars(str, i);
// 	}

// }

int count_subsequences(char*a){
	int len = strlen(a);
	int tot_subsets = (1<<len);
	return tot_subsets;
}

int main(){
	
	int tc;
	cin>>tc;
    char str[tc][100000];
    for(int i=0; i<tc; i++){
        cin>>str[i];
    }
    int i=0;
	while(tc>0){
		// generate_subsets(str);
		cout<<count_subsequences(str[i])<<endl;
        i++;
		tc--;
	}
	return 0;
}