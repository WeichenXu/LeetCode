class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        //using DP from down to top
        int n = triangle.size();
        //the original value of the bottom row
        vector<int> minLen(triangle.back());
        for(int i=n-2; i>=0; i--){
            for(int j=0; j<=i; j++){
                minLen[j] = min(minLen[j],minLen[j+1])+triangle[i][j];
            }
        }
        return minLen[0];
    }
    //int topDown(vector<vector<int>>& triangle, int level, int col, int cur, int min){
    //    if(col == )
    //}
private:
    int cols,rows;
};