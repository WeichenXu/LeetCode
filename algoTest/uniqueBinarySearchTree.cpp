class Solution {
public:
    int numTrees(int n) {
        int g[n+1] = {0};
        g[0] = g[1] = 1;
        for(int i=2; i<=n; ++i){
            // update each Unique for len(i) BST
            for(int j=0; j<i; ++j){
                g[i] += g[j]*g[i-1-j];
            }
        }
        return g[n];
    }
};