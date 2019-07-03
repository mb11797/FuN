#include<iostream>
using namespace std;

typedef pair<int, int> pairr;

pairr find_the_winner(int coins[], int s, int e, char turn){
    if(s>e){
        return {0, 0};
    }

    pairr p = {0, 0};
    pairr temp;
    if(turn=='p'){
        if(coins[s]>coins[e]){
            p.first += coins[s];
            s++;
        }
        else{
            p.first += coins[e];
            e--;
        }

        temp = find_the_winner(coins, s, e, 'n');
    }
    else if(turn=='n'){
        if(coins[s]>coins[e]){
            p.second += coins[s];
            s++;
        }
        else{
            p.second += coins[e];
            e--;
        }

        temp = find_the_winner(coins, s, e, 'p');
    }

    p.first += temp.first;
    p.second += temp.second;

    return p;
}

int main(){
    int n;
    cin>>n;

    int coins[n];
    for(int i=0; i<n; i++)
        cin>>coins[i];

    pairr p = find_the_winner(coins, 0, n-1, 'p');
    cout<<p.first<<endl;

    return 0;
}
