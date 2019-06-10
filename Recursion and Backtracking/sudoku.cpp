#include<iostream>
#include<cmath>
using namespace std;

bool can_place(int mat[][9], int n, int i, int j, int number){
    for(int x=0; x<n; x++){
        if(mat[x][j]==number || mat[i][x]==number)
            return false;
    }

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
            for(int j=0; j<n; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }

    if(j==n)
        return sudoku_solver(mat, n, i+1, 0);

    if(mat[i][j]!=0)
        return sudoku_solver(mat, n, i, j+1);

    for(int number=1; number<=9; number++){
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
    int mat[9][9] =
        {{5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}};

    sudoku_solver(mat, 9, 0, 0);

    return 0;
}