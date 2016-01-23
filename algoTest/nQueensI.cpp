class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> board;
        vector<vector<string>> solutions;
        generateBoard(board, solutions, n);
        return solutions;
    }
    bool isValidCross(vector<int>& board){
        for(int i=0; i<board.size(); i++){
            for(int j=i+1; j<board.size(); j++){
                if((j-i) == abs(board[i] - board[j])) return false;
            }
        }
        return true;
    }
    void generateBoard(vector<int>& board, vector<vector<string>>& solutions, int n){
        if(board.size() == n){
            if(isValidCross(board)){
                vector<string> solution;
                for(int i=0; i<n; i++){
                    string line(n, '.');
                    line[board[i]] = 'Q';
                    solution.push_back(line);
                }
                solutions.push_back(solution);
            }
            return;
        }
        for(int i=0; i<n; i++){
            bool exist = false;
            for(int j=0; j<board.size(); j++){
                if(board[j] == i){
                    exist = true;
                    break;
                }
            }
            if(!exist){
                board.push_back(i);
                if(isValidCross(board)) generateBoard(board, solutions, n);
                board.pop_back();
            }
        }
    }
    
};