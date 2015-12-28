class Solution {
public:
    
    int threeSumClosest(vector<int>& nums, int target) {
        // sort the nums
        sort(nums.begin(), nums.end());
        // two pointers
        //int array[nums.size()];
        int diff = INT_MAX;
        for(int i=0; i<nums.size(); i++){
            
            int pair1, pair2;
            int j=i+1, k=nums.size()-1;
            int cur_target = target - nums[i];
            while(j<k){
                pair1 = nums[j]; pair2 = nums[k];
                if(pair1 + pair2 > cur_target){
                    diff = abs(diff)<abs(pair1+pair2-cur_target)?diff:(pair1+pair2-cur_target);
                    k--;
                }
                else if(pair1 + pair2 == cur_target) return target;
                else{
                    diff = abs(diff)<abs(pair1+pair2-cur_target)?diff:(pair1+pair2-cur_target);
                    j++;
                }
            }
        }
        return diff+target;
    }
};