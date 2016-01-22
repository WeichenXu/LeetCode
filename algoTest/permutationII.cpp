class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        //sort(nums.begin(), nums.end());
        vector<int> order;
        vector<vector<int>> permutes;
        allOrder(0, nums, order, permutes);
        return permutes;
    }
    void allOrder(int cur, vector<int>& nums, vector<int>& order, vector<vector<int>>& permutes){
        if(cur == nums.size()-1){
            order.push_back(nums[cur]);
            permutes.push_back(order);
            order.pop_back();
            return;
        }
        vector<int> exist;
        for(int i=cur; i<nums.size(); i++){
            bool non = true;
            for(int j=0; j<exist.size(); j++){
                if(exist[j] == nums[i]) non = false;
            }
            if(non){
                exist.push_back(nums[i]);
                order.push_back(nums[i]);
                swap(nums[cur], nums[i]);
                allOrder(cur+1, nums, order, permutes);
                swap(nums[cur], nums[i]);
                order.pop_back();
            }
        }
    }
};