class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // check rows
        for(int i=0; i<board[0].size(); i++){
            bool map[9] = {false};
            for(int j=0; j<9; j++){
                if(board[j][i] == '.')  continue;
                if(map[board[j][i] - '1'])  return false;
                map[board[j][i]-'1'] = true;
            }
        }
        // check cols
        for(int i=0; i<board.size(); i++){
            bool map[9] = {false};
            for(int j=0; j<9; j++){
                if(board[i][j] == '.')  continue;
                if(map[board[i][j] - '1'])  return false;
                map[board[i][j]-'1'] = true;
            }
        }
        // check square
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                bool map[9] = {false};
                for(int k=0; k<3; k++){
                    for(int m=0; m<3; m++){
                        if(board[i*3+k][j*3+m] == '.')  continue;
                        if(map[board[i*3+k][j*3+m] - '1'])  return false;
                        map[board[i*3+k][j*3+m]-'1'] = true;
                    }
                }
            }
        }
        return true;
    }
    
};