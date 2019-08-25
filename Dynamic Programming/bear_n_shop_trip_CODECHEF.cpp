#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<cstring>
#include<iomanip>
using namespace std;

#define ld long double
#define N 50

//function to compute euclidian distance between two points
ld distance(pair<int, int> p1, pair<int, int> p2){
    int dx = p1.first - p2.first;
    int dy = p1.second - p2.second;
    return sqrt(dx*dx + dy*dy);
}

//make a distance array
ld dist[N][N] = {0};
ld dp[1<<13][N];            //1<=k<=13


//n is the no of shops except kitchen and k is the no of ingredients needed
int n, k;
string temp;
vector<pair<int, int>> coordinates;
vector<int>ingredients;

ld shop_trip(int mask, int idx){
    //base case
    if(mask == ((1<<k)-1) && idx == 0)
        return 0;

    //Top-Down DP - Overlapping subproblem
    if(dp[mask][idx] != -1)
        return dp[mask][idx];

    //try computing the answer
    dp[mask][idx] = INT_MAX;
    for(int i=0; i<=n; i++){
        if((mask|ingredients[i] != mask) || i == 0){
            dp[mask][idx] = min(dp[mask][idx], dist[idx][i] + shop_trip(mask|ingredients[i], i));
        }
    }
    return dp[mask][idx];
}

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        coordinates.clear();
        ingredients.clear();


        coordinates.push_back(make_pair(0, 0));
        ingredients.push_back(0);

        cin>>n>>k;

        //read the coordinates of each shop
        for(int i=0; i<n; i++){
            int x, y;
            cin>>x>>y;
            coordinates.push_back(make_pair(x, y));
        }

        //read n strings one for each shop
        int possible=0;                     //to check if all the shops together can actually fulfill the need of ingredients
        for(int i=0; i<n; i++){
            cin>>temp;
            reverse(temp.begin(), temp.end());
            int temp_mask=0;
            for(int i=0; i<k; i++){
                temp_mask |= (1<<i)*(temp[i]-'0');
            }
            possible |= temp_mask;
            ingredients.push_back(temp_mask);
        }

        int ALL = (1<<k)-1;
        if(possible != ALL){
            cout<<"-1"<<endl;
            continue;
        }

        //lets work upon the problem
        //1. Distance Array: Init it with Euclidian distances
        memset(dist, 0, sizeof(dist));
        for(int i=0; i<=n; i++){
            for(int j=0; j<=n; j++){
                dist[i][j] = distance(coordinates[i], coordinates[j]);
            }
        }

        //2. DP array for Top-Down DP (leave for now)
        for(int i=0; i<(1<<k); i++){
            for(int j=0; j<=n; j++){
                dp[i][j] = -1;
            }
        }

        ld ans = shop_trip(0, 0);                   //(mask, idx)
        cout<<fixed<<setprecision(10)<<ans<<endl;

    }

    return 0;
}
