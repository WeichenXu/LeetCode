class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        // sort the array
        // count all pairs based on each candidate
        sort(nums.begin(), nums.end());
        int count = 0, len = nums.size();
        for(int i=0; i<len-2; i++){
            int j=i+1, k=len-1;
            while(j<k){
                // add all possible pairs 
                if(nums[i]+nums[j]+nums[k] < target){
                    count += k-j;
                    j++;
                }
                else k--;
            }
        }
        return count;
    }
};