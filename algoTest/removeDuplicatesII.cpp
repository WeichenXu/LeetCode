class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0, j=i+2, size = nums.size();
        while(j<size){
            if(nums[j] != nums[i]){
                nums[i+2] = nums[j];
                i++;
            }
            j++;
        }
        return min(i+2, size);
    }
};