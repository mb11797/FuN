#include<iostream>
#include<stack>
using namespace std;

int arr[100][100];

int max_area_rectangle(int rows, int cols){
    stack<pair<int, int>> s;

    int max_area=0;
    for(int r=0; r<rows; r++){
        s.push(arr[r][0], 0);
        for(int c=0; c<cols; c++){
            if(arr[r][c] > s.top().first){
                s.push(arr[r][c], c);
            }
            else{
                max_area = max(max_area, s.top().first * )
            }
        }
    }
}

int main(){
    int rows, cols;
    cin>>rows>>cols;

    for(int i=0; i<rows; i++)
        for(int j=0; j<cols; j++)
            cin>>arr[i][j];

    cout<<max_area_rectangle(rows, cols)<<endl;

    return 0;
}
