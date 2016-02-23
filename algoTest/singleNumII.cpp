class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int x0=0;
        int x1=0;
        int m = 0;
        for(auto &i:nums){
            x1 ^= (x0&i);
            x0 ^= i;
            // count meet 3
            m = ~(x0&x1);
            x0 &= m;
            x1 &= m;
        }
        return x1|x0;
    }
};