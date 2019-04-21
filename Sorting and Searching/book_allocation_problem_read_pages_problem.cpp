#include<iostream>
using namespace std;

#define ll long long int

bool isValidConfig(ll books[], ll n, ll k, ll ans){
    ll current_pages = 0;
    ll students = 1;

    for(ll i=0; i<n; i++){
        if(current_pages+books[i]>ans){
            current_pages = books[i];               //reinitialize
            students++;
            if(students>k){
                return false;
            }
        }
        else{
            current_pages += books[i];
        }
    }
    return true;
}

//binarySearch - logN iterations and isValid - O(N) for each iteration
//Total Time = O(NlogN)

ll binarySearchBooks(ll books[], ll n, ll k){
    ll total_pages = 0;
    ll s=0, e=0;
    for(ll i=0; i<n; i++){
        total_pages += books[i];
        s = max(s, books[i]);
    }
    e = total_pages;
    ll final_ans = s;

    ll mid;
    while(s<=e){
        mid = (s+e)/2;

        if(isValidConfig(books, n, k, mid)){
            //True
            final_ans = mid;
            e = mid-1;
        }
        else{
            //False
            s = mid+1;
        }

    }
    return final_ans;
}

int main(){
    ll n;          //no of books
    ll k;          //no of students

    cin>>n>>k;

    ll books[100005];
    for(ll i=0; i<n; i++){
        cin>>books[i];
    }

    cout<<binarySearchBooks(books, n, k);

    return 0;
}
