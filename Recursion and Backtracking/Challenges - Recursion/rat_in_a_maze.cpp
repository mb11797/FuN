#include<iostream>
using namespace std;

void rat_in_a_maze(char maze[][10], int soln[][10], int m, int n, int i, int j){
    if(i==m && j==n){
        soln[i][j] = 1;
        return;
    }

    if(i>m || j>n || maze[i][j]=='X')
        return;

    soln[i][j] = 1;
    rat_in_a_maze(maze, soln, m, n, i, j+1);
    rat_in_a_maze(maze, soln, m, n, i+1, j);
    soln[i][j] = 0;
}

int main(){
    int m, n;
    cin>>m>>n;

    char maze[10][10];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            cin>>maze[i][j];

    int soln[10][10] = {0};
    rat_in_a_maze(maze, soln, m-1, n-1, 0, 0);
    for(int x=0; x<=m; x++){
        for(int y=0; y<=n; y++){
            cout<<soln[x][y]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}


