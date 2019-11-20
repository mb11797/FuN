#include<iostream>
using namespace std;

void findPath(char maze[][10], int m, int n, int path[][10], int i, int j, int &flag){
    //base case -> goal reached
    if(i==m-1 and j==n-1){
        path[i][j] = 1;
        for(int p=0; p<m; p++){
            for(int q=0; q<n; q++){
                cout<<path[p][q]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        flag = 1;
        return;
    }
    //out of bounds or X encountered
    else if(i>m or j>n or maze[i][j]=='X'){
        return;
    }
    //recursive case
    path[i][j] = 1;
    findPath(maze, m, n, path, i, j+1, flag);
    findPath(maze, m, n, path, i+1, j, flag);
    //backtracking
    path[i][j] = 0;
    return;
}

int main(){
    int m, n;
    cin>>m>>n;

    char maze[10][10];

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cin>>maze[i][j];
        }
    }
    int path[10][10] = {0};
    int flag = 0;
    findPath(maze, m, n, path, 0, 0, flag);

    if(flag==0){
        cout<<"NO PATH FOUND"<<endl;
    }
    return 0;
}
