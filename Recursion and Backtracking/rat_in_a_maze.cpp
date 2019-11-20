#include<iostream>
using namespace std;

bool rat_in_a_maze(char maze[][10], int m, int n, int i, int j){
    if(i==m and j==n){
        maze[i][j] = '1';
        //print
        for(int x=0; x<=m; x++){
            for(int y=0; y<=n; y++){
                cout<<maze[x][y]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return ;
    }

    if(i>m || j>n)
        return false;
    if(maze[i][j]=='X')
        return false;

    maze[i][j] = '1';
    bool right_success = rat_in_a_maze(maze, m, n, i, j+1);
    bool down_success = rat_in_a_maze(maze, m, n, i+1, j);

    //backtracking
    maze[i][j] = '0';


    if(right_success || down_success)
        return true;

    return false;
}

int main(){
    char maze[10][10] = {
                        "0000",
                        "00X0",
                        "000X",
                        "0X00"
    };
    int m=4, n=4;
    if(!rat_in_a_maze(maze, m-1, n-1, 0, 0))
        cout<<"Path not found!!!";

    return 0;
}
