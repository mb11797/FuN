#include<iostream>
using namespace std;

void tower_of_hanoi(int n, char src, char dest, char helper){
    //base case
    if(n==0)
        return;

    //rec case
    //first step: Move n-1 disks from src to helper
    tower_of_hanoi(n-1, src, helper, dest);

    cout<<"Move "<<n<<" disk from "<<src<<" to "<<dest<<endl;

    tower_of_hanoi(n-1, helper, dest, src);
    return;
}

int main(){
    int n;
    cin>>n;

    tower_of_hanoi(n, 'A', 'C', 'B');
    return 0;
}
