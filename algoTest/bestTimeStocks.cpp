class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // local[i][j] = max(global[i-1][j-1]+max(0,diff), local[i-1][j]+diff)
        // global[i][j] = max(glocal[i-1][j], local[i][j])
        if(k>=prices.size()) return maxPwithUnlimitK(prices);
        vector<int> local(k+1, 0);
        vector<int> global(k+1, 0);
        for(int i=1; i<prices.size(); i++){
            int diff = prices[i] - prices[i-1];
            for(int j=k; j>0; j--){
                local[j] = max(global[j-1]+diff, local[j]+diff);
                global[j] = max(global[j], local[j]);
            }
        }
        //printProfits(local);
        //printProfits(global);
        return global[k];
    }
    void printProfits(vector<int> &profits){
        for(int i=0; i<profits.size(); i++){
            cout<<profits[i]<<" ";
        }
        cout<<endl;
    }
    int maxPwithUnlimitK(vector<int>& prices) {
        int ans = 0;
        for(int i=1; i<prices.size(); i++){
            ans += max(0, prices[i]-prices[i-1]);
        }
        return ans;
    }
};