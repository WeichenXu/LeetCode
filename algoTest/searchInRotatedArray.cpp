class Solution {
public:
    int search(vector<int>& nums, int target) {
        return rangeSearch(nums, 0, nums.size()-1, target);
    }
    int rangeSearch(vector<int>& nums, int start, int end, int target){
        if(end - start <= 1){
            if(nums[start] == target)   return start;
            if(nums[end] == target) return end;
            return -1;
        }
        int middle = start + (end-start)/2;
        if(nums[middle] > nums[start]){
            if(target >= nums[start] && target <= nums[middle]) return rangeSearch(nums, start, middle, target);
            else    return rangeSearch(nums, middle+1, end, target);
        }
        else{
            if(target >= nums[middle] && target <= nums[end])   return rangeSearch(nums, middle, end, target);
            else    return rangeSearch(nums, start, middle -1, target);
        }
    }
};