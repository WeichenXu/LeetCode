class Solution {
public:
    bool canPermutePalindrome(string s) {
        unordered_map<char, int> chars;
        for(int i=0; i<s.length(); i++){
            if(chars.find(s[i]) == chars.end()){
                chars[s[i]] = 1;
            }
            else chars[s[i]]++;
        }
        int res = 1;
        for(auto &count : chars){
            if(count.second%2) res--;
            if(res<0) return false;
        }
        return true;
    }
};