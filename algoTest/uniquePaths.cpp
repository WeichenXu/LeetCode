class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row (n, 1);
        vector<vector<int>> boards (m, row);
        for(int i=1; i<m; i++){
            for(int j=1; j<n; j++){
                boards[i][j] = boards[i][j-1] + boards[i-1][j];
            }
        }
        return boards[m-1][n-1];
    }
};