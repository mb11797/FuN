#include<iostream>
#include<algorithm>
using namespace std;

bool myCompare(pair<string, int> p1, pair<string, int> p2){
    if(p1.second == p2.second)
        return p1.first < p2.first;

    return p1.second > p2.second;
}


int main(){
    pair<string, int> emp[10005];

    int min_sal;
    cin>>min_sal;

    int n;
    cin>>n;

    string name;
    int sal;
    for(int i=0; i<n; i++){
        cin>>name>>sal;
        emp[i].first = name;
        emp[i].second = sal;
    }

    sort(emp, emp+n, myCompare);

    for(int i=0;i<n; i++){
            if(emp[i].second>min_sal)
                cout<<emp[i].first<<" "<<emp[i].second<<endl;
    }
    return 0;
}
