#include<iostream>
#include<algorithm>
using namespace std;

int largest_unsafe_area(int w, int h, int n, int*x, int*y){
    sort(x, x+n);
    sort(y, y+n);

    int x_max = x[0] - 0;
    int y_max = y[0] - 0;
    for(int i=1; i<n; i++){
        if(x[i]-x[i-1]-1 > x_max){
            x_max = x[i] - x[i-1] - 1;
        }
        if(y[i]-y[i-1]-1 > y_max){
            y_max = y[i] - y[i-1] - 1;
        }
    }

    if(w-x[n-1] > x_max)
        x_max = w - x[n-1];
    if(h-y[n-1] > y_max)
        y_max = h - y[n-1];

    int largest_area = x_max * y_max;

    return largest_area;
}

int main(){
    int width, height, n_towers;
    cin>>width>>height>>n_towers;

    int x[n_towers];
    int y[n_towers];

    for(int i=0; i<n_towers; i++)
        cin>>x[i]>>y[i];

    cout<<largest_unsafe_area(width, height, n_towers, x, y)<<endl;

    return 0;
}
