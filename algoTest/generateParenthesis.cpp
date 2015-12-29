class Solution {
public:
    void appendParenthesis(string &cur, int n, int leftP, int rightP, vector<string>&allP){
        if((leftP+rightP) == n*2){
            allP.push_back(cur);
        }
        else{
            if(leftP < n){
                cur.append(1, '(');
                appendParenthesis(cur, n, leftP+1, rightP, allP);
                cur.resize(cur.length()-1);
            }
            if(rightP < leftP){
                cur.append(1, ')');
                appendParenthesis(cur, n, leftP, rightP+1, allP);
                cur.resize(cur.length()-1);
            }
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> allP;
        string cur = "";
        appendParenthesis(cur, n, 0, 0, allP);
        return allP;
    }
};