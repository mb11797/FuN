vector<int> Solution::getRow(int A) {
    
    vector<int> row;
    
    int n = 1;
    for(int col=0; col<=A; col++){
        row.push_back(n);
        n = n * (A - col) / (col + 1);
    }
    
    return row;
}
