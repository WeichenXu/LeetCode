class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> tmp;
        //res.push_back(tmp);
        findSubsets(0, nums, tmp, res);
        return res;
    }
    void findSubsets(int index, vector<int>& nums, vector<int>& cur, vector<vector<int>>& subsets){
        subsets.push_back(cur);
        if(index >= nums.size())  return;
        for(int i=index; i<nums.size(); i++){
            cur.push_back(nums[i]);
            findSubsets(i+1, nums, cur, subsets);
            cur.pop_back();
        }
    }
};