class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty() || board[0].empty())   return false;
        if(!word.length())  return true;
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> route(rows, vector<bool>(cols, true));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(findNext(board, route, 0, i, j, word))   return true;
            }
        }
        return false;
    }
    bool findNext(vector<vector<char>>& board, vector<vector<bool>>& routes, int match, int row, int col, string& word){
        //if(match >= word.length())  return true;
        if(!routes[row][col] || board[row][col] != word[match])  return false;
        routes[row][col] = false;
        match++;
        if(match == word.length())    return true;
        int rows = board.size(), cols = board[0].size();
        // up
        if(row && findNext(board, routes, match, row-1, col, word)) return true;
        // down
        if(row<rows-1 && findNext(board, routes, match, row+1, col, word))  return true;
        // left
        if(col && findNext(board, routes, match, row, col-1, word))  return true;
        // right
        if(col<cols-1 && findNext(board, routes, match, row, col+1, word))  return true;
        routes[row][col] = true;
        return false;
    }
};