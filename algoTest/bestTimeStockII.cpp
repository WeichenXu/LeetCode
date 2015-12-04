class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int i = 0, profit = 0, min;
        while(i<prices.size()){
            if(!i)  {
                min = prices[i];
            }
            else{
                if(prices[i] > min){
                    profit += prices[i]-min;
                }
                min = prices[i];
            }
            i++;
        }
        return profit;
    }
};