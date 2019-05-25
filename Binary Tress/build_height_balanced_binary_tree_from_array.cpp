#include<iostream>
using namespace std;

class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node*build_Height_Balanced_Binary_Tree_from_Array(int*a, int s, int e){
    //base case
    if(s>e)
        return NULL;
    //Recursive Case

}

int main(){


    return 0;
}
