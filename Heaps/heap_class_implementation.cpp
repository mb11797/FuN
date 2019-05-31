#include<iostream>
#include<vector>
using namespace std;

//Implementation of heap using vector(Dynamic array)
class Heap{
    vector<int> v;
    //configuration
    bool minHeap;

    //comparator
    bool compare(int a, int b){
        if(minHeap)
            return a<b;
        else
            return a>b;
    }

    void heapify(int i){                    //i - from index
        int left = 2*i;
        int right = 2*i + 1;

        int minIndex = i;
        if(left<v.size() && compare(v[left], v[i]))
            minIndex =
    }

public:
    Heap(bool type = true){
        minHeap = type;
        //block the 0th index
        v.push_back(-1);
    }

    void push(int data){
        //insert at last
        v.push_back(data);
        //Heapify => take that element to correct position to restore the heap property
        int index = v.size() - 1;
        int parent = index/2;

        while(index>1 && compare(v[index], v[parent])){
            swap(v[index], v[parent]);
            index = parent;
            parent = parent/2;
        }
    }

    bool empty(){
        return v.size()==1;
    }
    int top(){
        return v[1];
    }

    void pop(){
        //remove the topmost element
        int last = v.size() - 1;
        swap(v[1], v[last]);
        v.pop_back();
        heapify(1);
    }
};


int main(){
    Heap h(false);
    h.push(5);
    h.push(15);
    h.push(2);
    h.push(20);
    h.push(3);

    cout<<h.top()<<endl;

    return 0;
}
