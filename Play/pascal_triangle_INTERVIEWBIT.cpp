vector<vector<int> > Solution::solve(int A) {
    
    vector<vector<int>> pascalT;
    
    for(int row=0; row<A; row++){
        int n = 1;
        vector<int> pascalTRow;
        for(int col=0; col<=row; col++){
            pascalTRow.push_back(n);
            n = n * (row - col) / (col + 1);
        }
        
        pascalT.push_back(pascalTRow);
    }
    
    return pascalT;
}
