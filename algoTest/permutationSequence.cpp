class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums;
        int curOrders=1, cur;
        string result = "";
        for(int i=1; i<=n; i++){
            nums.push_back(i);
            curOrders*=i;
        }
        k--;
        for(int i=1; i<=n; i++){
            curOrders = curOrders/(n-i+1);
            cur = k/curOrders;
            result.append(1,'0'+nums[cur]);
            nums.erase(nums.begin()+cur);
            k -= cur*curOrders;
        }
        return result;
    }
};