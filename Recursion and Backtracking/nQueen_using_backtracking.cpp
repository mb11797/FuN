#include<iostream>
using namespace std;

bool is_safe(int board[][10], int n, int i, int j){
    //same column check
    for(int row=0; row<j; row++){
        if(board[row][j]==1)
            return false;
    }

    //left diagonal check
    int x = i;
    int y = j;
    while(x>=0 && y>=0){
        if(board[x][y]==1)
            return false;
        x--;
        y--;
    }

    //right diagonal check
    x = i;
    y = j;
    while(x>=0 && y<n){
        if(board[x][y]==1)
            return false;
        x--;
        y++;
    }
    return true;
}

bool solve_nQueen(int board[][10], int n, int i){
    if(i==n){
        //Print the board
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(board[i][j]==1)
                    cout<<"Q ";
                else
                    cout<<"_ ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }
    for(int j=0; j<n; j++){
        if(is_safe(board, n, i, j)){
            board[i][j] = 1;
            bool next_queen_aage_rakh_paaye = solve_nQueen(board, n, i+1);
            if(next_queen_aage_rakh_paaye)
                return true;
            board[i][j] = 0;
        }
    }
    return false;
}


int main(){
    int n;
    cin>>n;

    int board[10][10] = {0};

    solve_nQueen(board, n, 0);

    return 0;
}
