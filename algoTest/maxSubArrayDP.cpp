class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSub = INT_MIN;
        int array[nums.size()+1];
        array[0] = 0;
        for(int i=0; i<nums.size(); i++){
            if(array[i] > 0){
                array[i+1] = array[i]+nums[i];
            }
            else array[i+1] = nums[i];
            maxSub = max(maxSub, array[i+1]);
        }
        return maxSub;
    }
};