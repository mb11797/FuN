#include<iostream>
#include<algorithm>
using namespace std;

#define ll long long int

bool myCompare(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second){
        return p1.first<p2.first;
    }
    else
        return p1.second>p2.second;

}

int main(){
    int min_sal;
    cin>>min_sal;

    ll n;
    cin>>n;

    ll index = 0;
    pair<string, int> emp[100000];
    string name;
    int sal;

    for(ll i=0; i<n; i++){
        cin>>name>>sal;
        if(sal>=min_sal){
            emp[index].first = name;
            emp[index].second = sal;
            index++;
        }
    }

    sort(emp, emp+index, myCompare);

    for(ll i=0; i<index; i++){
        cout<<emp[i].first<<" "<<emp[i].second<<endl;
    }

    return 0;
}
