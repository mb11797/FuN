#include<iostream>
using namespace std;

void merge(int *a,int *x,int *y,int s,int e){
    int i = s;
    int mid = (s+e)/2;
    int j = mid+1;
    int k = s;

    while(i<=mid && j<=e){
        if(x[i]<y[j]){
            a[k] = x[i];
            i++; k++;
        }
        else{
            a[k] = y[j];
            j++;
            k++;
        }

    }


    while(i<=mid){
        a[k] = x[i];
        i++;
        k++;
    }
    while(j<=e){
        a[k] = y[j];
        j++;
        k++;
    }
}

void mergeSort(int *a,int s,int e){
    ///Base Case 0 or 1 element
    if(s>=e){
        return;
    }
    ///Rec Case
    ///1. Divide
        int x[10000],y[10000];
        int mid = (s+e)/2;
        for(int i=s;i<=mid;i++){
            x[i] = a[i];
        }
        for(int i=mid+1;i<=e;i++){
            y[i] = a[i];
        }

    ///2. Sort x and y
        mergeSort(x,s,mid);
        mergeSort(y,mid+1,e);

    ///3. Merge x and y
        merge(a,x,y,s,e);
}

int main(){
   int n;
   cin>>n;
   int a[100000];
   for(int i=0;i<n;i++){
       cin>>a[i];
   }
    mergeSort(a,0,n-1);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
return 0;
}
