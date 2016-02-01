class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        res.push_back(0);
        if(n<=0) return res;
        
        res.push_back(1);
        for(int i=2; i<=n; i++){
            int high = 1<<(i-1), curSize = res.size();
            for(int j=curSize-1; j>=0; j--){
                //cout<<high<<" "<<res[i]<<endl;
                res.push_back(high+res[j]);
            }
        }
        return res;
    }
};