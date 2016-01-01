class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2)    return;
        int backMax = nums.back(), i=nums.size()-2,j;
        int tmp;
        while(i>=0){
            if(backMax > nums[i]){
                j = i+1;
                sort(nums.begin()+j, nums.end());
                while(1){
                    if(nums[j] > nums[i]){
                        tmp = nums[j];
                        nums[j] = nums[i];
                        nums[i] = tmp;
                        return;
                    }
                    j++;
                }
            }
            backMax = nums[i];
            i--;
        }
        if(i<0) sort(nums.begin(), nums.end());
        return;
    }
};