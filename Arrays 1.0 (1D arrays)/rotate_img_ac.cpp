#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int img[n][n];
    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin>>img[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<img[i][j]<<" ";
        }
        cout<<endl;
    }

    //Mirror Image
    for(int i=0; i<n; i++){
        for(int j=0; j<n/2; j++){
            int temp = img[i][j];
            img[i][j] = img[i][n-1-j];
            img[i][n-1-j] = temp;
        }
    }
    cout<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<img[i][j]<<" ";
        }
        cout<<endl;
    }

    //Transpose
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int temp = img[i][j];
            img[i][j] = img[j][i];
            img[j][i] = temp;
        }
    }
    cout<<endl;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cout<<img[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
