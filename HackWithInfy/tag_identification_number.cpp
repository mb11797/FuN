#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'numOfIds' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts STRING pool as parameter.
 */

int numOfIds(string pool) {
    if(pool.size()<11)
        return 0;

    if(pool.size()==11 && pool[0]!=8){
        return 0;
    }

    int count=0;
    if(pool.size()>=11){
        if(pool[0]=='8'){
            count = 1 + numOfIds(pool.substr(10));
        }
        else{
            count = numOfIds(pool.substr(1));
        }
    }
    return count;
`}

int main()
{
//    ofstream fout(getenv("OUTPUT_PATH"));
//
//    string pool;
//    getline(cin, pool);
//
//    int result = numOfIds(pool);
//
//    fout << result << "\n";
//
//    fout.close();

    string pool;
    cin>>pool;
    cout<<numOfIds(pool)<<endl;

    return 0;
}
