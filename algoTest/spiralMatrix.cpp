class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> order;
        int rows = matrix.size(), cols, rowStart = 0, colStart = 0;
        if(!rows) return order;
        cols = matrix[0].size();
        while(rows>0 && cols>0){
            getNSpiral(matrix, rowStart, rows, colStart, cols, order);
            rows-=2;
            rowStart++;
            cols-=2;
            colStart++;
        }
        return order;
    }
    void getNSpiral(vector<vector<int>>& matrix, int rowStart, int rows, int colStart, int cols, vector<int>& order){
        for(int i=0; i<cols; i++) order.push_back(matrix[rowStart][colStart+i]);
        for(int i=0; i<rows-2; i++) order.push_back(matrix[rowStart+1+i][colStart+cols-1]);
        if(rows>1) for(int i=cols-1; i>=0; i--) order.push_back(matrix[rowStart+rows-1][colStart+i]);
        if(cols>1) for(int i=0; i<rows-2; i++) order.push_back(matrix[rowStart+rows-2-i][colStart]);
    }
};