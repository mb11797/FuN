#include<iostream>
using namespace std;

int maximum_circles(int c[], int r[], int n){
    int s[n], e[n];
    for(int i=0; i<n; i++){
        s[i] = c[i] - r[i];
        e[i] = c[i] + r[i];
    }

    int count=0;

    int j=0;
    cout<<j<<" - ("<<s[j]<<", "<<e[j]<<")"<<endl;

    count++;

    for(int k=1; k<n; k++){
        if(s[k]>=e[j]){
            cout<<k<<" - ("<<s[k]<<", "<<e[k]<<")"<<endl;
            j=k;
            count++;
        }
    }
    return count;
}

int main(){
    int c[] = {1,2,3,4};
    int r[] = {1,1,1,1};

    int n = sizeof(c)/sizeof(int);

    int m_c = maximum_circles(c, r, n);

    cout<<"Maximum circles selected: "<<m_c<<endl;
    cout<<"Circles removed: "<<n-m_c;
    return 0;
}
