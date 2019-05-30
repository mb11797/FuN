#include<iostream>
#include<queue>
using namespace std;

//Thumb rule:
//One of the queues should always be made empty, because it is used a supportive queue

template<typename T>
class stackUsingQueue{
private:
    queue<T> q1;              //q1 should always contain the stack elements
    queue<T> q2;              //maintain definition that q2 should always be empty
public:
    void push(T x){
        q1.push(x);
    }

    void pop(){
        int n = q1.size();
        //pop n-1 elements from q1 to q2
        for(int i=0; i<n-1; i++){
            q2.push(q1.front());
            q1.pop();
        }
        if(!q1.empty()){
            q1.pop();
            //maintain the definition that q2 should always be empty
            swap(q1, q2);
        }
    }

    T top(){
        int n = q1.size();
        for(int i=0; i<n-1; i++){
            q2.push(q1.front());
            q1.pop();
        }
        T topElement;
        if(!q1.empty()){
            topElement = q1.front();
            q2.push(q1.front());
            q1.pop();
            //maintain the definition that q2 should always be empty
            swap(q1, q2);
        }
        return topElement;
    }

    bool stackEmpty(){
        return q1.size()==0;
    }
    int sizeOfStack(){
        return q1.size();
    }
};

int main(){
    stackUsingQueue<char> s;
    char temp;
    cin>>temp;

    while(temp!='0'){
        s.push(temp);
        cin>>temp;
    }

    cout<<endl<<s.sizeOfStack()<<endl;

    while(!s.stackEmpty()){
        cout<<s.top()<<"<-";
        s.pop();
    }

    return 0;
}
