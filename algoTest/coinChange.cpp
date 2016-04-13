/*
    dp with amount*coins
    track min coins for each amount, update it with each candidate coin
    return the final min comparing to the Max
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // for amount <= 0
        if(amount < 0 || coins.empty())  return -1;
        int Max = amount+1;
        vector<int> dp(Max, Max);
        dp[0] = 0;
        for(int i=1; i<= amount; ++i){
            for(int j=0; j<coins.size(); ++j){
                if(coins[j] <= i)    dp[i] = min(dp[i], dp[i-coins[j]]+1);
            }
        }
        return dp[amount]<Max?dp[amount]:-1;
    }
};