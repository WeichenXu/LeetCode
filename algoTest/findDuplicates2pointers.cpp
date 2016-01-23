class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0, fast = 0;
        int finder = 0;
        while(1){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast) break;
        }
        while(1){
            finder = nums[finder];
            slow = nums[slow];
            if(slow == finder)  return slow;
        }
    }
};