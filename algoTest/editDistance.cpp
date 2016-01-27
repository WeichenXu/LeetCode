class Solution {
public:
    int minDistance(string word1, string word2) {
        int LCS[word2.length()+1][word1.length()+1];
        for(int i=0; i<=word1.length(); i++) LCS[0][i] = i;
        for(int i=0; i<=word2.length(); i++) LCS[i][0] = i;
        for(int i=1; i<=word2.length(); i++){
            for(int j=1; j<=word1.length(); j++){
                if(word1[j-1] == word2[i-1]) LCS[i][j] = LCS[i-1][j-1];
                else LCS[i][j] = min(min(LCS[i-1][j-1], LCS[i-1][j]), LCS[i][j-1])+1;
            }
        }
        return LCS[word2.length()][word1.length()];
    }
};