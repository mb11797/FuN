#include<iostream>
using namespace std;

int rat_in_a_maze(char maze[][10], int m, int n, int i, int j){
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
        return 1;
    }

    if(i>m || j>n)
        return 0;
    if(maze[i][j]=='X')
        return 0;

    int cnt = 0;
    maze[i][j] = '1';

    cnt += rat_in_a_maze(maze, m, n, i, j+1);
    cnt += rat_in_a_maze(maze, m, n, i+1, j);

    //backtracking
    maze[i][j] = '0';

    return cnt;
}

int main(){
    char maze[10][10] = {
                        "0000",
                        "00X0",
                        "000X",
                        "0X00"
    };
    int m=4, n=4;
    int cnt = rat_in_a_maze(maze, m-1, n-1, 0, 0);
    cout<<"Count: "<<cnt<<endl;
    return 0;
}

