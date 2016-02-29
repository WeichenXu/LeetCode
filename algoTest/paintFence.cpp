class Solution {
public:
    
    int numWays(int n, int k) {
        if(n<=2) return n==0||k==0?0:pow(k,n);
        int diff=k*(k-1),same=k;
        for(int i=3; i<=n; i++){
            int diff_old = diff;
            // the new combinations of last 2 colors different
            diff = (same+diff)*(k-1);
            // the new combinations of last 2 colors same
            // cause we append same color for all diff combination, exactly ONE per instance
            same = diff_old;
        }
        return diff+same;
    }
};