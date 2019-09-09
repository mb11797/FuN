#include<iostream>
#include<algorithm>
using namespace std;

int arr[100][100];

int largest_area_rectangle_with_1s_considering_cols_permutations(int rows, int cols){
    int hist_dp[rows][cols];
    for(int c=0; c<cols; c++){
        for(int r=0; r<rows; r++){
            if(r == 0){
                hist_dp[r][c] = arr[r][c];
            }
            else if(r > 0){
                if(arr[r][c] == 0){
                    hist_dp[r][c] = 0;
                }else{
                    hist_dp[r][c] = hist_dp[r-1][c] + arr[r][c];
                }
            }
        }
    }

    for(int r=0; r<rows; r++){
        for(int c=0; c<cols; c++){
            cout<<hist_dp[r][c]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    int ans=INT_MIN;
    for(int r=0; r<rows; r++){
        sort(hist_dp[r], hist_dp[r]+cols);
        int max_area = INT_MIN;
        for(int c=0; c<cols; c++){
            cout<<hist_dp[r][c]<<" ";
            max_area = max(max_area, hist_dp[r][c]*(cols-c));
        }
        ans = max(ans, max_area);
        cout<<endl;
    }
    return ans;
}

int main(){

    int n, m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>arr[i][j];
    cout<<endl;

    cout<<largest_area_rectangle_with_1s_considering_cols_permutations(n, m)<<endl;

    return 0;
}
