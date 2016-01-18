class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> combinations;
        vector<int> cur;
        solve(candidates, 0, combinations, cur, target);
        return combinations;
    }
    void solve(vector<int>& candidates, int j, vector<vector<int>>& combinations, vector<int>& cur, int target){
        int next_target;
        for(int i=j; i<candidates.size(); i++){
            if(i!=j && candidates[i] == candidates[i-1])   continue;
            next_target = target-candidates[i];
            if(next_target >= 0){
                cur.push_back(candidates[i]);
                if(!next_target) combinations.push_back(cur);
                else solve(candidates, i+1, combinations, cur, target - candidates[i]);
                cur.pop_back();
            }
            else return;
        }
    }
};