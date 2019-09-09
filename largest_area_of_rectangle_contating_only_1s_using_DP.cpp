#include<iostream>
#include<stack>
using namespace std;

int arr[100][100];

int max_area_rectangle(int rows, int cols){
    stack<int> s;

    int r, c;
    int max_area=0;
    for(r=0; r<rows; r++){
        for(c=0; c<cols; c++){
            if(!s.empty()){
                if(arr[r][c] < arr[r][s.top()]){
                    while(arr[r][c] < arr[r][s.top()]){
                        int temp = arr[r][s.top()];
                        s.pop();
                        if(s.empty()){
                            max_area = max(max_area, temp*c);
                            break;
                        }
                        else{
                            max_area = max(max_area, temp*(c - s.top() - 1));
                        }
                    }
                    s.push(c);
                }
                else{
                    s.push(c);
                }
            }
            else{
                s.push(c);
            }
        }
        while(!s.empty()){
            int temp = arr[r][s.top()];
            s.pop();
            if(s.empty()){
                max_area = max(max_area, temp*c);
                break;
            }
            else{
                max_area = max(max_area, temp*(c - s.top() - 1));
            }
        }

        //updating the histogram considering second row
        if(r < rows-1){
            for(int c=0; c<cols; c++){
                if(arr[r+1][c] == 0){
                    arr[r+1][c] = 0;
                }
                else{
                    arr[r+1][c] += arr[r][c];
                }
            }
        }

    }
    return max_area;
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
