class Solution {
public:
    int pureNum(string n, bool sign){
        int nums = 0;
        for(int i=0; i<n.length(); i++){
            if(n[i]-'0'<0 || n[i]-'0'>9){
                if(sign && i == 0 && (n[i] == '+' || n[i] == '-'))  continue;
                else return -1;
            }
            else nums++;
        }
        return nums;
    }
    bool isNumber(string s) {
        // remove blanks
        removeBlank(s);
        int point = findChar(s, '.');
        int e = findChar(s, 'e');
        int befP=0, aftP=0;
        if(!s.length()) return false;
        // no number before .
        if(point >= 0){
            befP = pureNum(s.substr(0, point), true);
            if(befP<0)  return false;
        }
        if(e<0){    // after .
            if(point>=0)    aftP = pureNum(s.substr(point+1, s.length()-1-point), false);
            else    aftP = pureNum(s.substr(point+1, s.length()-1-point), true);
            if(aftP<0)  return false;
        }
        else{
            // between . & e
            if(point>=0)    aftP = pureNum(s.substr(point+1, e-1-point), false);
            else    aftP = pureNum(s.substr(point+1, e-1-point), true);
            if(aftP<0)  return false;
            // after e
            if(e == s.length()-1 || pureNum(s.substr(e+1, s.length()-1-e), true) <= 0)    return false;
        }
        if(befP<=0 && aftP <=0) return false;
        return true;
    }
    void removeBlank(string &s){
        int i = 0, j = s.length()-1;
        while(i<s.length() && s[i] == ' ')  i++;
        while(j>=0 && s[j] == ' ')  j--;
        s = s.substr(i, j-i+1);
    }
    int findChar(string& s, char c){
        for(int i=0; i<s.length(); i++){
            if(s[i] == c)   return i;
        }
        return -1;
    }
    
};