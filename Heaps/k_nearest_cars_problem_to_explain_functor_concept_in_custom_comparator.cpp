//Nearest k cars among the n cars around the origin

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Car{
public:
    int x;
    int y;
    int id;             //say model no

    Car(int id, int x, int y){
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int dist(){
        return x*x + y*y;               //either take square root or not, there will be no difference in actual logic here
    }

    void print(){
        cout<<"ID: "<<id<<"->";
        cout<<"Location: ("<<x<<", "<<y<<")"<<endl;
    }
};

//Functor - functional object

class CarCompare{
public:
    //Method to overload () operator
    bool operator()(Car a, Car b){
        return a.dist()>b.dist();           //Min heap => for nearest cars
    }
};

int main(){
    priority_queue<Car, vector<Car>, CarCompare> pq;

    int x[10] = {5,6,17,18,9,11,0,3};
    int y[10] = {1,-2,8,9,10,91,1,2};

    //insert these in pq
    for(int i=0; i<8; i++){
        Car c(i, x[i], y[i]);
        pq.push(c);
    }

    int k;
    cin>>k;

    //Min Heap
    while(!pq.empty() && k--){
        Car p = pq.top();
        p.print();
        pq.pop();
    }

    return 0;
}
