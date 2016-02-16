class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy(INT_MIN), sell(0), preBuy(0), preSell(0);
        for(auto& price : prices){
            preBuy = buy;
            buy = max(preSell-price, buy);
            preSell = sell;
            sell = max(preBuy+price, preSell);
        }
        return sell;
    }
};