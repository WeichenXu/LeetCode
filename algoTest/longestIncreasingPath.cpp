class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return 0;
        vector<vector<int>> lens(matrix.size(), vector<int>(matrix[0].size(),0));
        int res = 0;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                res = max(dfs(matrix, lens, i, j), res);
            }
        }
        return res;
    }
    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& lens, int curR, int curC){
        int rows = matrix.size(), cols = matrix[0].size();
        if(lens[curR][curC]) return lens[curR][curC];
        lens[curR][curC] = 1;
        int directions[4][2] = {{0,-1}, {-1,0}, {1,0}, {0,1}};
        for(int i=0; i<4; i++){
            int n_r = curR+directions[i][0], n_c = curC+directions[i][1];
            if(n_r>=0 && n_r<rows && n_c>=0 && n_c<cols && matrix[n_r][n_c]>matrix[curR][curC]){
                lens[curR][curC] = max(lens[curR][curC], dfs(matrix, lens, n_r, n_c)+1);
            }
        }
        return lens[curR][curC];
    }
};