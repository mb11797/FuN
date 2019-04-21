//Find out the sqrt of a no upto p no o decimal places using binary search
#include<iostream>
using namespace std;

float squareRoot(int no, int p){
    int s=0, e=no;
    float ans;
    int mid;

    while(s<=e){
        mid = (s+e)/2;
        if(mid*mid==no){
            ans = mid;
            break;
        }
        else if(mid*mid<no){
            ans = mid;
            s = mid + 1;
        }
        else{
            e = mid - 1;
        }
    }
    //Fractional part
    float inc = 0.1;
    for(int i=0; i<p; i++){
        while(ans*ans<=no){
            ans += inc;
        }
        //ans*ans>no
        ans = ans - inc;
        inc = inc/10;
    }
    return ans;
}

int main(){
    cout<<squareRoot(49,1)<<endl;
    cout<<squareRoot(10,3)<<endl;
    cout<<squareRoot(2,2)<<endl;
    return 0;
}
