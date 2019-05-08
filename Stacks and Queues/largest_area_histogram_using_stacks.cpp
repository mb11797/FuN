#include<iostream>
#include<stack>
using namespace std;

int main(){
    int n = 7;
    stack<int> s;
    int arr[n] = {6,2,5,4,5,1,6};
    int area = 0;
    for(int i=0; i<n; i++){
//        if(s.empty()){
//            s.push(i);
//            area = max(area, arr[s.top()]*i);
//        }
        cout<<i<<endl;
        if(!s.empty()){
            if(arr[i] < arr[s.top()]){                     //obstacle identified - so pop the top of stack
                cout<<i<<endl;
                while(arr[i]<arr[s.top()]){
                    int temp = arr[s.top()];
                    s.pop();
                    if(s.empty()){
                        area = max(area, temp*i);
                    }
                    else{
                        area = max(area, temp*(i - s.top() - 1));
                    }
                }
                s.push(i);
            }
            else{
                cout<<i<<endl;
                s.push(i);
            }
        }
        else{
            cout<<i<<endl;
            s.push(i);
        }
        cout<<i<<endl;
    }

    cout<<"Area: "<<area<<endl;

    return 0;
}
