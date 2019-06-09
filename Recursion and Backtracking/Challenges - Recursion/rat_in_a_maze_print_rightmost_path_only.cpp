#include<iostream>
using namespace std;

bool rat_in_a_maze(char maze[][100], int soln[][100], int m, int n, int i, int j){
    if(i==m && j==n){
        soln[i][j] = 1;
        for(int x=0; x<=m; x++){
            for(int y=0; y<=n; y++){
                cout<<soln[x][y]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        return true;
    }

    if(i>m || j>n || maze[i][j]=='X')
        return false;

    soln[i][j] = 1;

    bool ryt_success = rat_in_a_maze(maze, soln, m, n, i, j+1);
    if(ryt_success)
        return true;

    bool down_success = rat_in_a_maze(maze, soln, m, n, i+1, j);
    if(down_success)
        return true;

    soln[i][j] = 0;
//    if(ryt_success || down_success)
//        return true;
    return false;
}

int main(){
    int m, n;
    cin>>m>>n;

    char maze[100][100];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>maze[i][j];

    int soln[100][100] = {0};
    if(!rat_in_a_maze(maze, soln, m-1, n-1, 0, 0))
        cout<<-1<<endl;

    return 0;
}


