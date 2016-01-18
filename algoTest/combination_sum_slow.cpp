class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        map<int, vector<vector<int>>> combinations;
        for(int i=0; i<candidates.size(); i++){
            if(i && candidates[i] == candidates[i-1])   continue;
            int j=1, cur = candidates[i];
            vector<int> combination;
            while(j*cur <= target){
                for(int k=1; k<=target-j*cur; k++){
                    if(combinations.find(k) != combinations.end()){
                        for(int m=0; m<combinations[k].size(); m++){
                            if(combinations[k][m].back() == cur)    continue;
                            combination = combinations[k][m];
                            for(int l=0; l<j;l++)   combination.push_back(cur);
                            combinations[k+j*cur].push_back(combination);
                        }
                    }
                }
                combination.clear();
                for(int k=0; k<j; k++)  combination.push_back(cur);
                combinations[j*cur].push_back(combination);
                j++;
            }
        }
        return combinations[target];
    }
};