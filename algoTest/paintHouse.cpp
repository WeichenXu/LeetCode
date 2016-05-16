class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int houses = costs.size();
        int budgets[houses+1][3];
        for(int i=0; i<3; ++i)  budgets[0][i] = 0;
        for(int i=1; i<=houses; ++i){
            for(int j=0; j<3; ++j){
                budgets[i][j] = costs[i-1][j]+min(budgets[i-1][(j+1)%3], budgets[i-1][(j+2)%3]);
            }
        }
        return min(min(budgets[houses][0], budgets[houses][1]), budgets[houses][2]);
    }
};