#include<iostream>
using namespace std;

void spiral_print_arr(int m, int n, int arr[10][10]){
    int i, r=0, c=0;
    //i->iterator
    //r->starting row index
    //m->ending row index
    //c->starting col. index
    //n->ending col. index

    while(r<m && c<n){
        //first col. from rem. cols.
        for(i=r; i<m; i++){
            cout<<arr[i][c]<<", ";
        }
        c++;

        //last row from rem. rows
        for(i=c; i<n; i++){
            cout<<arr[m-1][i]<<", ";
        }
        m--;

        //last col. from rem. cols
        if(c<n){
            for(i=m-1; i>=r; i--){
                cout<<arr[i][n-1]<<", ";
            }
            n--;
        }

        //first row from rem. rows
        if(r<m){
            for(i=n-1; i>=c; i--){
                cout<<arr[r][i]<<", ";
            }
            r++;
        }
    }
    cout<<"END";
}

int main(){
    int m, n;
    cin>>m>>n;
    int arr[10][10];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>arr[i][j];
        }
        cout<<endl;
    }

    cout<<endl;

    spiral_print_arr(m,n,arr);

    return 0;
}
