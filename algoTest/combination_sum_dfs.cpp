class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> tmp;
        solve(candidates, 0, tmp, target, combinations);
        return combinations;
    }
    void solve(vector<int>& candidates, int j, vector<int>& cur, int target, vector<vector<int>>& combinations){
        if(!target){
            combinations.push_back(cur);
            return;
        }
        if(target < 0)  return;
        for(int i=j; i<candidates.size(); i++){
            cur.push_back(candidates[i]);
            solve(candidates, i, cur, target-candidates[i], combinations);
            cur.pop_back();
        }
    }
};