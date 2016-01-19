class Solution {
public:
    string multiply(string num1, string num2) {
       vector<string> nums;
       
       for(int i=0; i<num2.length(); i++){
           vector<string> add;
           string zeros(num2.length()-i-1, '0');
           for(int j=0; j<(num2[i]-'0'); j++){
               add.push_back(num1+zeros);
           }
           //cout<<plus(add)<<endl;
           nums.push_back(plus(add));
       }
       return plus(nums);
    }
    string plus(vector<string> &nums){
       if(nums.empty()) return "0";
       int pre = 0, cur = 0,digitSum;
       bool  exist;
       string result = "";
       while(1){
           digitSum = 0;
           exist = false;
           for(int i=0; i<nums.size(); i++){
               if(nums[i].length() > cur){
                   exist = true;
                   digitSum += nums[i][nums[i].length()-cur-1] - '0';
               }
           }
           if(!exist && !pre) break;
           digitSum += pre;
           pre = digitSum/10;
           digitSum = digitSum%10;
           result.insert(result.begin(), digitSum+'0');
           cur++;
       }
       if(result[0] == '0') return "0";
       return result;
    }
};