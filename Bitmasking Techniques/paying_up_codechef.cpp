#include<iostream>
using namespace std;

void filterSubsets(int*notes, int no, int tAmt){
    int amt=0;
    int i=0;
    while(no>0){
        (no&1) ? amt+=notes[i] : amt+=0;
        no = (no>>1);
        i++;
    }
    if(amt==tAmt){
        cout<<"Yes ";
    }
}

void generateSubsets(int tNotes, int tAmt, int *notes){
    int range = (1<<tNotes)-1;
    for(int i=0; i<=range; i++){
        filterSubsets(notes, i, tAmt);
    }
}

int main(){
    int tNotes, tAmt;
    cin>>tNotes>>tAmt;
    int notes[20];
    for(int i=0; i<tNotes; i++){
        cin>>notes[i];
    }
    generateSubsets(tNotes, tAmt, notes);
    return 0;
}
