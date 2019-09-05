#include<iostream>
using namespace std;

int arr[100];
int dp[101][101] = {0};

int max_score_of_Modi_ji(int n){
    //base case - 2 possible                1.=>if(i>j) return 0;                2.=>if(be==en+1) return max(arr[be], arr[en]);
    //len = 2
    for(int i=0; i<n-1; i++){
        dp[i][i+1] = max(arr[i], arr[i+1]);
    }

    for(int len=3; len<=n; len++){
        int start = 0;
        int end = n-len;

        while(start<=end){
            int end_window = start+len-1;
            dp[start][end_window] = max(
                                        arr[start] + min(dp[start+2][end_window], dp[start+1][end_window-1]),
                                        arr[end_window] + min(dp[start+1][end_window-1], dp[start][end_window-2])
                                        );
            start++;
        }
    }

    return dp[0][n-1];
}

int main(){
    int n;
    cin>>n;

    int total_sum=0;
    for(int i=0; i<n; i++){
        cin>>arr[i];
        total_sum += arr[i];
    }

    int Modi = max_score_of_Modi_ji(n);
    int Trump = total_sum - Modi;

    cout<<"Modi's score: "<<Modi<<endl;
    cout<<"Trump's score: "<<Trump<<endl;
    cout<<"Modi wins by "<<Modi - Trump<<" point margin."<<endl;

    return 0;
}
