class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tempMin, max=0;
        for(int i=0; i<prices.size(); i++){
            if(!i)  tempMin = prices[i];
            else{
                if(tempMin > prices[i]){
                    tempMin = prices[i];
                }
                else{
                    max = (prices[i] - tempMin)>max?(prices[i] - tempMin):max;
                }
            }
        }
        return max;
    }
};