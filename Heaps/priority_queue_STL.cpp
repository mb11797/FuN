#include<iostream>
#include<queue>                             //for priority_queue
//#include<functional>                        //if greater<int> does not work
#include<vector>
using namespace std;

//#include<bits/stdc++.h>                     //Master header file

int main(){
    priority_queue<int> pq_max;                                     //by default - max heap
    priority_queue<int, vector<int>, greater<int>> pq_min;          //min heap syntax

    int a[10] = {5,6,17,18,9,11};

    //insert these in pq_max
    for(int i=0; i<6; i++){
        pq_max.push(a[i]);
        pq_min.push(a[i]);
    }

    //Heap - Max
    cout<<"Max Heap:"<<endl;
    while(!pq_max.empty()){
        cout<<pq_max.top()<<" ";
        pq_max.pop();
    }
    cout<<endl;

    //Heap - Min
    cout<<"Min Heap:"<<endl;
    while(!pq_min.empty()){
        cout<<pq_min.top()<<" ";
        pq_min.pop();
    }
    cout<<endl;

    return 0;
}
