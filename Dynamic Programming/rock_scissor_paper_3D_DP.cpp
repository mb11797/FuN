#include<iostream>
#include<iomanip>
using namespace std;

#define F(i, a, b) for(int i=a; i<=b; i++)
#define ld double

ld memo[105][105][105];

/*
Sample Input:
3
2 2 2
2 1 2
1 1 3
*/


void set_DP(){
    F(i, 0, 102)
        F(j, 0, 102)
            F(k, 0, 102)
                memo[i][j][k] = -1.0;
    return;
}

//Rock survives the game
ld f1(int r, int s, int p){
    if(r==0 || s==0){
        return 0.0;
    }
    if(p==0){
        return 1.0;
    }

    //overlapping subproblems case
    if(memo[r][s][p] != -1){
        return memo[r][s][p];
    }

    ld total = r*s + s*p + p*r;
    ld prob = 0.0;
    prob += f1(r-1, s, p)*((p*r)/total);       //paper kills rock
    prob += f1(r, s-1, p)*((r*s)/total);       //rock kills scissor
    prob += f1(r, s, p-1)*((s*p)/total);       //scissor kills paper

    return memo[r][s][p] = prob;
}

//Scissor survives the game
ld f2(int r, int s, int p){
    if(s==0 || p==0){
        return 0.0;
    }
    if(r==0){
        return 1.0;
    }

    //overlapping subproblems case
    if(memo[r][s][p] != -1){
        return memo[r][s][p];
    }

    ld total = r*s + s*p + p*r;
    ld prob = 0.0;
    prob += f2(r-1, s, p)*((p*r)/total);       //paper kills rock
    prob += f2(r, s-1, p)*((r*s)/total);       //rock kills scissor
    prob += f2(r, s, p-1)*((s*p)/total);       //scissor kills paper

    return memo[r][s][p] = prob;
}

//Paper survives the game
ld f3(int r, int s, int p){
    if(p==0 || r==0){
        return 0.0;
    }
    if(s==0){
        return 1.0;
    }

    //overlapping subproblems case
    if(memo[r][s][p] != -1)
        return memo[r][s][p];

    ld total = r*s + s*p + p*r;
    ld prob = 0.0;
    prob += f3(r-1, s, p)*((p*r)/total);         //paper kill rock
    prob += f3(r, s-1, p)*((r*s)/total);         //rock kills scissor
    prob += f3(r, s, p-1)*((s*p)/total);         //scissor kills paper

    return memo[r][s][p] = prob;
}

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        int r, s, p;
        cin>>r>>s>>p;

        set_DP();
        ld ans1 = f1(r, s, p);
        set_DP();
        ld ans2 = f2(r, s, p);
        set_DP();
        ld ans3 = f3(r, s, p);

        cout<<fixed<<setprecision(9)<<ans1<<" "<<ans2<<" "<<ans3<<" "<<endl;
    }

    return 0;
}
