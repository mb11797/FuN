#include<iostream>
#include<stack>
using namespace std;

#define ll long long

ll max_area_histogram(ll*hist, ll n){
    stack<ll> s;

    ll area = 0;
    ll i = 0;
    for(i=0; i<n; i++){
        if(!s.empty()){
            if(hist[i]<hist[s.top()]){
                while(hist[i]<hist[s.top()]){
                    ll top = hist[s.top()];
                    s.pop();
                    if(s.empty()){
                        area = max(area, top*i);
                        break;
                    }
                    else{
                        area = max(area, top*(i - s.top() - 1));
                    }
                }
                s.push(i);
            }
            else{
                s.push(i);
            }
        }
        else{
            s.push(i);
        }
    }
    //pop the remaining elements while calculating the area based on considering them as min
    while(!s.empty()){
        ll top = hist[s.top()];
        s.pop();
        if(s.empty()){
            area = max(area, top*i);
            break;
        }
        else{
            area = max(area, top*(i - s.top() - 1));
        }
    }
    return area;
}


int main(){
//    int hist[5] = {1,2,3,4,5};
//    int hist[7] = {10, 40, 30, 70, 10, 30, 60};
    ll n;
    cin>>n;

    ll hist[n];
    for(ll i=0; i<n; i++)
        cin>>hist[i];

    cout<<max_area_histogram(hist, n)<<endl;

    return 0;
}
