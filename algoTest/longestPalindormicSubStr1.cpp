class Solution {
public:
    string longestPalindrome(string s) {
        string maxEven="", maxOdd="";
        // iterate all char, find max even sub, center at i, i+1
        for(int i=0; i<s.length()-1;i++){
            int left = i, right = i+1;
            while(left>=0 && right<s.length() && s[left] == s[right]){
                right++;
                left--;
            }
            right--,left++;
            if(right-left+1 > maxEven.length()){
                maxEven = s.substr(left, right-left+1);
            }
        }
        // find max odd sub
        for(int i=0; i<s.length(); i++){
            int left = i-1, right=i+1;
            while(left>=0 && right<s.length() && s[left] == s[right]){
                right++;
                left--;
            }
            right--,left++;
            if(right-left+1 > maxOdd.length()){
                maxOdd = s.substr(left, right-left+1);
            }
        }
        return maxEven.length()>maxOdd.length()?maxEven:maxOdd;
    }
};