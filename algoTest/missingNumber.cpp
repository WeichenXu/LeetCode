class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int result = 0;
        int tmp=1;
        for(auto &i:nums){
            result ^= (i^tmp);
            tmp++;
        }
        return result;
    }
};