class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        bool firstRowZero = false, firstColZero = false;
        for(int i=0; i<rows; i++){
            if(!matrix[i][0]){
                firstColZero = true;
                break;
            }
        }   
        for(int j=0; j<cols; j++){
            if(!matrix[0][j]){
                firstRowZero = true;
                break;
            }
        }
        
        for(int i=1; i<rows; i++){
            bool zero = false;
            for(int j=0; j<cols; j++){
                if(matrix[i][j] == 0){
                    zero = true; 
                    break;
                } 
            }
            if(zero) matrix[i][0] = 0;
        }
        for(int j=1; j<cols; j++){
            bool zero = false;
            for(int i=0; i<rows; i++){
                if(matrix[i][j] == 0){
                    zero = true; 
                    break;
                } 
            }
            if(zero) matrix[0][j] = 0;
        }
        
        for(int i=1; i<cols; i++){
            if(matrix[0][i] == 0){
                for(int j=0; j<rows; j++)   matrix[j][i] = 0;
            }
        }
        for(int i=1; i<rows; i++){
            if(matrix[i][0] == 0){
                for(int j=0; j<cols; j++)   matrix[i][j] = 0;
            }
        }
        if(firstRowZero){
            for(int j=0; j<cols; j++)   matrix[0][j] = 0;
        }
        if(firstColZero){
            for(int i=0; i<rows; i++)   matrix[i][0] = 0;
        }
    }
};