class Solution {
public:
    int getIndex(vector<int>& nums, int num, int time){
        for(int i=0; i<nums.size(); i++){
            if(num == nums[i]){
                time -- ;
                if(!time)   return i+1;
            }  
        }
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> twoSum;
        vector<int> original(nums);
        // sort
        sort(nums.begin(), nums.end());
        // two pointers search 
        int i=0, j=nums.size()-1;
        int pair1, pair2;
        bool finded = false;
        while(i < nums.size()-1 && i < j){
            pair1 = nums[i];
            if((pair2 = nums[j]) > target-pair1)    j--;
            else if(pair2 == target-pair1){
                finded = true;  break;
            }
            else{
                i++;
            }
            //cout<<pair1<<"  "<<pair2<<endl;
        }
        // find the index of two sums
        if(!finded) return twoSum;
        if(pair1 == pair2){
            pair1 = getIndex(original, pair1,1);
            pair2 = getIndex(original, pair2,2);
        }
        else{
        //cout<<pair1<<" "<<pair2<<endl;
            pair1 = getIndex(original, pair1,1);
            pair2 = getIndex(original, pair2,1);
        }
        if(pair1 > pair2){
            i = pair1;
            pair1 = pair2;
            pair2 = i;
        }
        twoSum.push_back(pair1);
        twoSum.push_back(pair2);
        return twoSum;
    }
};