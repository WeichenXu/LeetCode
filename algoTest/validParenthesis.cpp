class Solution {
public:
    bool isValid(string s) {
        stack<char> p;
        for(int i=0; i<s.length(); i++){
            switch (s[i]){
                case ')':
                    if(!p.size() || p.top() != '(') return false;
                    p.pop();
                    break;
                case ']':
                    if(!p.size() || p.top() != '[') return false;
                    p.pop();
                    break;
                case '}':
                    if(!p.size() || p.top() != '{') return false;
                    p.pop();
                    break;
                default:
                    p.push(s[i]);
                    break;
            }
        }
        if(p.size())    return false;
        return true;
    }
};