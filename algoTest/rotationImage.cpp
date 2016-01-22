class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       int n = matrix.size();
       int rows = n/2 , cols = n/2;
       
       if(n%2 == 1) rows++;
       for(int i=0; i<rows; i++){
           for(int j=0; j<cols; j++){
               int tmp1 = matrix[i][j], tmp2 = matrix[j][n-1-i], tmp3 = matrix[n-1-i][n-1-j], tmp4 = matrix[n-1-j][i];
               matrix[i][j] = tmp4;
               matrix[j][n-1-i] = tmp1;
               matrix[n-1-i][n-1-j] = tmp2;
               matrix[n-1-j][i] = tmp3;
           }
       }
    }
};