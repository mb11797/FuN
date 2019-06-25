#include<iostream>
#include<algorithm>
using namespace std;

class Item{
public:
    int value;
    int weight;

    Item(int v, int w) : value(v), weight(w)
    {}
};

bool myComparator(Item a, Item b){
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1>r2;
}

double fractional_knapsack(Item*arr, int w, int n){
    sort(arr, arr+n, myComparator);

    int curr_weight = 0;
    double final_value = 0;


    for (int i = 0; i < n; i++) {
        cout << arr[i].value << "  " << arr[i].weight << " : "
             << ((double)arr[i].value / arr[i].weight) << endl;
    }

    for(int i=0; i<n; i++){
        if(curr_weight+arr[i].weight <= w){
            curr_weight += arr[i].weight;
            final_value += arr[i].value;
        }
        else{
            int remain = w - curr_weight;
            final_value += arr[i].value * ((double)remain / arr[i].weight);
            break;
        }
    }
    return final_value;
}



int main(){
    int w=50;
    Item arr[] = {{60,10}, {100,20}, {120,30}};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout<<fractional_knapsack(arr, w, n)<<endl;
    return 0;
}
