class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> traces;
        for(int i=0; i<nums.size(); i++){
            bool largest = true;
            for(int j=0; j<traces.size(); j++){
                if(nums[i]<=traces[j]){
                    largest = false;
                    traces[j] = nums[i];
                    break;
                }
            }
            if(largest) traces.push_back(nums[i]);
        }
        return traces.size();
    }
};