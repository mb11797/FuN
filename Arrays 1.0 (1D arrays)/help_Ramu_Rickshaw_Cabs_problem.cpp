#include<iostream>
using namespace std;

int main(){
    int t;
    cin>>t;

    int c1, c2, c3, c4;
    int n, m;
    int rick[1000], cab[1000];
    while(t--){
        cin>>c1>>c2>>c3>>c4;

        cin>>n>>m;

        for(int i=0; i<n; i++){
            cin>>rick[i];
        }
        for(int i=0; i<m; i++){
            cin>>cab[i];
        }

        int ricksCost=0;
        for(int i=0; i<n; i++){
            ricksCost += min(rick[i]*c1, c2);
        }
        ricksCost = min(ricksCost, c3);

        int cabsCost=0;
        for(int i=0; i<m; i++){
            cabsCost += min(cab[i]*c1, c2);
        }
        cabsCost = min(cabsCost, c3);

        int finalCost = min(c4, ricksCost+cabsCost);
        cout<<finalCost<<endl;
    }
    return 0;
}
