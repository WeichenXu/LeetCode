class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // use the array self to represent flag array
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>0 && nums[i]<=nums.size()){
                while(nums[i] != i+1){
                    if(nums[i] < 0 || nums[i] > nums.size() || nums[nums[i]-1] == nums[i]) break;
                    int tmp = nums[i];
                    nums[i] = nums[tmp-1];
                    nums[tmp-1] = tmp;
                }
            }
        }
        // find the first missing positive ele
        for(int i=0; i<nums.size(); i++){
            //cout<<nums[i]<<endl;
            if(nums[i] != i+1)  return i+1;
        }
        return nums.size()+1;
    }
};