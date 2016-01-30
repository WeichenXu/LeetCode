class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> tmp;
        findCombine(1, n, k, tmp, res);
        return res;
    }
    void findCombine(int cur, int n, int k, vector<int> &curCombine, vector<vector<int>>& allCombines){
        if(k<=0 || k>(n-cur+1))    return;
        if(k == 1){
            for(int i=cur; i<=n; i++){
                curCombine.push_back(i);
                allCombines.push_back(curCombine);
                curCombine.pop_back();
            }
            return;
        }
        for(int i=cur; i< n; i++){
            curCombine.push_back(i);
            findCombine(i+1, n, k-1, curCombine, allCombines);
            curCombine.pop_back();
        }
    }
};