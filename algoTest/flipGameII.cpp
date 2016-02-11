class Solution {
public:
    bool canWin(string& s) {
        if(s.length()<2) return false;
        for(int i=0; i<s.length()-1; i++){
            if(s[i]=='+' && s[i+1]=='+'){
                s[i] = '-';
                s[i+1] = '-';
                bool win = canWin(s);
                s[i] = '+';
                s[i+1] = '+';
                if(!win) return true;
            }
        }
        return false;
    }
};