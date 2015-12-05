class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices.size(), min=INT_MAX, max = INT_MIN, profit = 0, profits = 0;
        if(!m)  return 0;
        int trade1[m] = {0};
        int trade2[m] = {0};
        for(int i=0; i<m; i++){
            if(min > prices[i]){    // save temp min
                min = prices[i];
            }
            profit = profit>(prices[i]-min)?profit:(prices[i]-min);
            trade1[i] = profit;
        }
        profit = 0;
        for(int j=0; j<m; j++){
            int i = m-1-j;
            if(max < prices[i]){    // save temp max
                max = prices[i];
            }
            profit = profit>(max - prices[i])?profit:(max-prices[i]);
            profits = profits>(profit + trade1[i])?profits:(profit+trade1[i]);
        }
        return profits;
    }
};