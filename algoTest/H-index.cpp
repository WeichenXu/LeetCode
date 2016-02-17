class Solution {
public:
    static bool greater(int a, int b){return a>b;}
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater);
        int i=0;
        while(i<citations.size()){
            if(citations[i]<i+1) return i;
            i++;
        }
        return citations.size();
    }
};