#include<iostream>
using namespace std;

static int result = INT_MAX;;

void find_min_path(int src[], int dest[], int pipeline[][20], int n, bool f[], int a, bool f1, int time){
    if(f1){
        time += abs(src[0] - dest[0]) + abs(src[1] - dest[1]);
        result = min(result, time);
        return;
    }
    if(a == n){
        time += abs(src[0] - dest[0]) + abs(src[1] - dest[1]);
        result = min(result, time);
        return;
    }

    for(int j=0; j<n; j++){
        if(!f[j]){
            f[j] = true;
            int t = abs(src[0] - pipeline[0][j]) + abs(src[1] - pipeline[1][j]);
            int b = src[0];
            int c = src[1];
            src[0] = pipeline[2][j];
            src[1] = pipeline[3][j];
            find_min_path(src, dest, pipeline, n, f, a+1, f1, time+t+pipeline[4][j]);
            f[j] = false;
            src[0] = b;
            src[1] = c;


            //calculating time required if the pipeline was chosen in reverse state
            f[j] = true;
            t = abs(src[0] - pipeline[2][j]) + abs(src[1] - pipeline[3][j]);
            b = src[0];
            c = src[1];
            src[0] = pipeline[0][j];
            src[1] = pipeline[1][j];
            find_min_path(src, dest, pipeline, n, f, a+1, f1, time+t+pipeline[4][j]);
            f[j] = false;
            src[0] = b;
            src[1] = c;
        }
    }
    find_min_path(src, dest, pipeline, n, f, a+1, !f1, time);
    return;
}



int main(){
    int tc;
    cin>>tc;
    int i=0;
    while(i<tc){
        int n;
        cin>>n;

        int src[2];
        cin>>src[0]>>src[1];

        int dest[2];
        cin>>dest[0]>>dest[1];

        int pipeline[5][20];                        //for pipeline[5][n]
        bool*f = new bool[20];                      //for f[n]

        for(int i=0; i<n; i++){
            for(int j=0; j<5; j++){
                cin>>pipeline[j][i];
            }
            f[i] = false;
        }

//        for(int i=0; i<n; i++){
//            for(int j=0; j<5; j++){
//                cout<<pipeline[j][i]<<" ";
//            }
//            cout<<f[i]<<endl;
//        }

        find_min_path(src, dest, pipeline, n, f, 0, false, 0);
        cout<<"#"<<i<<": "<<result<<endl;
        result = INT_MAX;
        i++;
    }


    return 0;
}
