#include<iostream>
#include<queue>
#include<vector>
#include<functional>
#include<cstdio>
using namespace std;

void query_print(priority_queue<int, vector<int>, greater<int>> pq){

    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }
    cout<<endl;
    return;
}


int main(){
    int no;

    priority_queue<int, vector<int>, greater<int>> pq;

    int cs = 0;
    int k = 3;

    while(scanf("%d", &no) != EOF){
//        cout<<no<<" ";
        if(no==-1)
            query_print(pq);
        else if(cs<k){
            pq.push(no);
            cs++;
        }
        else{
            if(no>pq.top()){
                pq.pop();
                pq.push(no);
            }
        }
    }
    return 0;
}
