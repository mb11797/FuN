#include <bits/stdc++.h>
using namespace std;

void wildcard(char *inp, string out, int i){
	//cout << inp << "    " << out << "\n";
	if(inp[i] == '\0'){
		out[i] = '\0';
		cout << out << "\n";
		return;
	}
	if(inp[i] == '?'){
		out[i] = '0';
		//cout << i << "\n";
		wildcard(inp, out, i+1);
		out[i] = '1';
		//cout << i << "\n";
		wildcard(inp, out, i+1);
	}
	else {
		out[i] = inp[i];
		//cout << i << "\n";
		wildcard(inp, out, i+1);
	}
}

int main(){
	char inp[] = "1?01";
	char out[] = "1?01";

	/*cout << strlen(out);*/
	wildcard(inp, out, 0);
	return 0;
}
