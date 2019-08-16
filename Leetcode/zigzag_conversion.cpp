#include<iostream>
using namespace std;

string convert(string s, int numRows){
    int numCols=0;
    int n_s_e_c = numRows-2;            //no of single element cols
    int n = s.size();

    int i=n;
    int flag=1;
    while(i > 0){
        if(flag){
            i = i-numRows;
//            for(int r=0; r<numRows; r++){
//                cout<<
//            }
            numCols++;
            flag=0;
        }
        else{
            if(i < n_s_e_c)
                n_s_e_c = i;

            for(int j=0; j<n_s_e_c; j++){
                i = i - 1;
                numCols++;
            }
            flag=1;
        }
    }
    cout<<numCols<<endl;

    char mat[numRows][numCols];
    for(int r=0; r<numRows; r++){
        for(int c=0; c<numCols; c++){
            mat[r][c] = '\0';
        }
    }


    i=0;
    flag=1;
    int c=0;
    n_s_e_c = numRows - 2;
    while(i < n){
        if(flag){
            for(int r=0; r<numRows; r++){
                mat[r][c]=s[i];
                i++;
            }
            c++;
            flag=0;
        }
        else{
            if(n-1-i < n_s_e_c){
                n_s_e_c = n - 1 - i;
            }
            int dec = numRows-2;
            for(int j=0; j<n_s_e_c; j++){
                mat[dec][c] = s[i];
                dec--;
                i++;
                c++;
            }
            flag=1;
        }
    }

    string zigzag = "";
    int k=0;
    for(int r=0; r<numRows; r++){
        for(int c=0; c<numCols; c++){
            if(mat[r][c] >= 'A' && mat[r][c] <= 'Z' || mat[r][c]=='\0'){
                if(mat[r][c] != '\0')
                    zigzag += mat[r][c];
            }
            cout<<mat[r][c]<<" ";
        }
        cout<<endl;
    }

    return zigzag;
}

int main(){
    int n;
    cin>>n;
    cout<<convert("PAYPALISHIRING", n)<<endl;
//    cout<<"1\0 23"<<endl;
    return 0;
}
