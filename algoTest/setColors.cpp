class Solution {
public:
    void sortColors(vector<int>& nums) {
        int r = 0, w = 0, b = 0;
        int size = nums.size(), i=0;
        while(r+w+b < size){
            if(nums[i] == 0){
                i++;
                r++;
            }
            if(nums[i] == 1){
                w++;
                nums[i] = nums[size-b-w];
            }
            if(nums[i] == 2){
                b++;
                nums[i] = nums[size-b-w];
            }
        }
        for(int i=0; i<w; i++) nums[r+i] = 1;
        for(int i=0; i<b; i++) nums[r+w+i] = 2;
    }
};