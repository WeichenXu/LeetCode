class Solution {
public:
    int nthUglyNumber(int n) {
        // the index of smallest ugly number index
        int k0=0,k1=0,k2=0;
        vector<int> nums(n,0);
        nums[0] = 1;
        for(int i=1; i<n; i++){
            nums[i] = min(min(nums[k0]*2, nums[k1]*3), nums[k2]*5);
            if(nums[i]%2 == 0)  k0++;
            if(nums[i]%3 == 0)  k1++;
            if(nums[i]%5 == 0)  k2++;
        }
        return nums[n-1];
    }
};