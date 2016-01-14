class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range;
        range.push_back(searchFirstTarget(nums, 0, nums.size()-1, target));
        range.push_back(searchLastTarget(nums, 0, nums.size()-1, target));
        return range;
    }
    int searchFirstTarget(vector<int>& nums, int start, int end, int target){
        if(end-start<2){
            if(nums[start] == target)   return start;
            if(nums[end] == target) return end;
            return -1;
        }
        int middle = start + (end-start)/2;
        if(target <= nums[middle]){
            return searchFirstTarget(nums, start, middle, target);
        }
        return searchFirstTarget(nums, middle+1, end, target);
    }
    int searchLastTarget(vector<int>& nums, int start, int end, int target){
        if(end-start<2){
            if(nums[end] == target)   return end;
            if(nums[start] == target) return start;
            return -1;
        }
        int middle = start + (end-start)/2;
        if(target >= nums[middle]){
            return searchLastTarget(nums, middle, end, target);
        }
        return searchLastTarget(nums, start, middle-1, target);
    }
};