class Solution {
public:
    inline int c2n(char c){
        switch(c){
            case 'I':   return 1;
            case 'V':   return 5;
            case 'X':   return 10;
            case 'L':   return 50;
            case 'C':   return 100;
            case 'D':   return 500;
            case 'M':   return 1000;
            default:    return 0;
        }
    }
    int romanToInt(string s) {
        int res=0;
        for(int i=0; i<s.length(); i++){
            if(i && c2n(s[i]) > c2n(s[i-1]))    res += c2n(s[i]) - 2*c2n(s[i-1]);
            else res += c2n(s[i]);
        }
        return res;
    }
};