class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        if(nums.size()<4) return quadruplets;
        sort(nums.begin(), nums.end());
        int i,j,k,l;
        for(int i=0; i<(nums.size()-3); i++){
            while(i && i<nums.size()-3 && nums[i] == nums[i-1]) i++;
            for(int j=i+1; j<nums.size()-2; j++){
                while(j>i+1 && j<nums.size()-2 && nums[j] == nums[j-1]) j++;
                k=j+1; l = nums.size()-1;
                int cur_target = target - nums[i] - nums[j];
                while(k < l){
                    //cout<<k<<"  "<<l<<endl;
                    while(k>j+1 && k < l &&nums[k] == nums[k-1])    k++;
                    if(k >= l) break;
                    int sum2 = nums[k]+nums[l];
                    if(sum2 > cur_target) l--;
                    else if(sum2 == cur_target){
                        vector<int> quadruplet;
                        quadruplet.push_back(nums[i]);
                        quadruplet.push_back(nums[j]);
                        quadruplet.push_back(nums[k]);
                        quadruplet.push_back(nums[l]);
                        quadruplets.push_back(quadruplet);
                        k++;l--;
                    }
                    else k++;
                }
            }
        }
        return quadruplets;
    }
};