class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int diff = 0;
        for(auto &i:nums)   diff ^= i;
        // find the rightmost bit with 1
        diff &= -diff;//-diff = ~(diff-1)
        vector<int> res(2,0);
        for(auto &i:nums){
            if(i&diff)  res[0]^=i;
            else res[1]^=i;
        }
        return res;
    }
};