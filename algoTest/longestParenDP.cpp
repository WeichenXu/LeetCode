class Solution {
public:
    int longestValidParentheses(string s) {
        int dp[s.length()+1] = {0};
        int maxLen = 0;
        for(int i=1; i<=s.length(); i++){
            int j = i-2-dp[i-1];
            if(s[i-1] == '(' || j<0 || s[j] == ')') dp[i] = 0;
            else{
                dp[i] = dp[j] + dp[i-1] + 2;
                maxLen = max(maxLen, dp[i]);
            }
            //cout<<i<<" "<<dp[i]<<endl;
        }
        return maxLen;
    }
};