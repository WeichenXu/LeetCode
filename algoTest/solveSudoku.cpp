class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        recursiveSolve(board, 0, 0);
    }
    bool isValidSudoku(vector<vector<char>>& board, int r, int c){
        char val = board[r][c];
        // check row and col
        for(int i=0; i<9; i++){
            if(board[r][i] == val && i!=c)  return false;
            if(board[i][c] == val && i!=r)  return false;
        }
        // check 3*3 block
        int preR = r, preC = c;
        r = r/3*3;
        c = c/3*3;
        for(int i=r; i<r+3; i++){
            for(int j=c; j<c+3; j++){
                if(board[i][j] == val && !(i==preR && j==preC)) return false;
            }
        }
        return true;
    }
    bool recursiveSolve(vector<vector<char>>& board, int r, int c){
        // if r==9 return, else try all choices
        if(r == 9) return true;
        bool known = false;
        if(board[r][c] != '.') known = true;
        
        int nextR, nextC;
        if(c == 8){
            nextR = r+1; nextC = 0;
        }
        else {
            nextR = r;
            nextC = c+1;
        }
        if(!known){
            for(int i=1; i<=9; i++){
                board[r][c] = '0'+i;
                if(isValidSudoku(board, r, c) && recursiveSolve(board, nextR, nextC))   return true;
                else{
                    board[r][c] = '.';
                }
            }
            return false;
        }
        else{
            return (isValidSudoku(board, r, c) && recursiveSolve(board, nextR, nextC));
        }
    }
};