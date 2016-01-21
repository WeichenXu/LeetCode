class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> order;
        vector<vector<int>> permutes;
        allOrders(0, nums, order, permutes);
        return permutes;
    }
    void allOrders(int cur, vector<int>& nums, vector<int>& order, vector<vector<int>>& permutes){
        if(cur == nums.size()-1){
            order.push_back(nums[cur]);
            permutes.push_back(order);
            order.pop_back();
            return;
        }
        for(int i = cur; i<nums.size(); i++){
            order.push_back(nums[i]);
            swap(nums[cur], nums[i]);
            allOrders(cur+1, nums, order, permutes);
            swap(nums[cur], nums[i]);
            order.pop_back();
        }
    }
};