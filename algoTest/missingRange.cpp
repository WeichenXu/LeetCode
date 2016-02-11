class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        vector<string> res;
        int cur = lower, i=0;
        while(i<nums.size()){
            int tmp = nums[i];
            if(tmp == cur+1){
                res.push_back(to_string(cur));
            }
            else if(tmp > cur){
                res.push_back(to_string(cur)+"->"+to_string(tmp-1));
            }
            cur = tmp+1;
            i++;
        }
        if(cur<upper)  res.push_back(to_string(cur)+"->"+to_string(upper));
        else if(cur == upper) res.push_back(to_string(upper));
        return res;
    }
};