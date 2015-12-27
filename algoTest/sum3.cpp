class Solution {
public:
    class pairs{
    public:
        int a;
        int b;
        pairs(int aa, int bb){a = aa; b = bb;}
        friend bool operator==(const pairs&l, const pairs&r){
            return l.a == r.a && l.b == r.b;
        }
    };
    
    vector<pairs> sum2pairs(vector<int>& nums, int index, int target){
        vector<pairs> result;
        int i=index, j = nums.size()-1;
        int pair1, pair2;
        while(i < j){
            pair1 = nums[i];
            if((pair2 = nums[j]) > target - pair1){
                j--;
            }
            else if(pair2 == target - pair1){
                pairs add = pairs(pair1, pair2);
                i++; j--;
                result.push_back(add);
                while(i && nums[i] == nums[i-1]) i++;
                while(j && nums[j] == nums[j+1]) j--;
            }
            else    i++;
        }
        return result;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        // sort the nums
        sort(nums.begin(), nums.end());
        // iterate to 2+1 sum
        vector<pairs> pairs2;
        vector<vector<int>> pairs3;
        for(int i=0; i < nums.size(); i++){
            if(i && nums[i] == nums[i-1])   continue;
            pairs2 = sum2pairs(nums, i+1, -nums[i]);
            for(int j=0; j<pairs2.size(); j++){
                vector<int> sum3;
                sum3.push_back(nums[i]);
                sum3.push_back(pairs2[j].a);
                sum3.push_back(pairs2[j].b);
                pairs3.push_back(sum3);
            }
        }
        return pairs3;
    }
};