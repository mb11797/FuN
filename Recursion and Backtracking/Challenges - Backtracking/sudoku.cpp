#include<iostream>
#include<cmath>
using namespace std;

bool can_place(int mat[][9], int n, int i, int j, int number){
    //column check
    for(int x=0; x<n; x++){
        if(mat[x][j]==number || mat[i][x]==number)
            return false;
    }

    //subgrid check
    int rn = sqrt(n);
    int sx = (i/rn)*rn;
    int sy = (j/rn)*rn;
    for(int x=sx; x<sx+rn; x++){
        for(int y=sy; y<sy+rn; y++){
            if(mat[x][y]==number)
                return false;
        }
    }
    return true;
}

bool sudoku_solver(int mat[][9], int n, int i, int j){
    if(i==n){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++)
                cout<<mat[i][j]<<" ";
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    if(j==n)
        return sudoku_solver(mat, n, i+1, 0);
    if(mat[i][j]!=0)
        return sudoku_solver(mat, n, i, j+1);

    for(int number=1; number<=n; number++){
        if(can_place(mat, n, i, j, number)){
            mat[i][j] = number;

            bool could_we_solve = sudoku_solver(mat, n, i, j+1);
            if(could_we_solve)
                return true;
        }
    }
    //backtrack
    mat[i][j] = 0;
    return false;
}

int main(){
    int n;
    cin>>n;
    int mat[9][9];
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin>>mat[i][j];

    sudoku_solver(mat, n, 0, 0);

    return 0;
}
