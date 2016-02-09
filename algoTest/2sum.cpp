class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0, j=numbers.size()-1;
        vector<int> pair;
        while(i<j){
            int tmp = numbers[i]+numbers[j];
            if(tmp == target){
                pair.push_back(i+1);
                pair.push_back(j+1);
                return pair;
            }
            if(tmp < target)    i++;
            else j--;
        }
    }
};