#include<iostream>
using namespace std;

#define ll long long

bool isValidConfig(ll books[], ll nb, ll ns, ll ans){
    ll students = 1;
    ll current_pages=0;
    for(ll i=0; i<nb; i++){
        if(current_pages+books[i]>ans){
            current_pages = books[i];
            students++;
            if(students>ns){
                return false;
            }
        }
        else{
            current_pages += books[i];
        }
    }
    return true;
}

int binarySearchBooks(ll books[], ll nb, ll ns){
    ll s = 0, e = 0;
    ll total_pages = 0;
    for(ll i=0; i<nb; i++){
        total_pages += books[i];
        s = max(s, books[i]);
    }
    e = total_pages;
    ll mid;
    ll ans=0;
    while(s<=e){
        mid = (s+e)/2;
        if(isValidConfig(books, nb, ns, mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
    }
    return ans;
}

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        ll nb, ns;
        cin>>nb>>ns;

        ll books[nb];
        for(ll i=0; i<nb; i++){
            cin>>books[i];
        }
        cout<<binarySearchBooks(books, nb, ns)<<endl;
    }
    return 0;
}
