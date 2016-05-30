class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if(nums.size()<2)   return 0;
        // find the min&max among the nums
        int minNum = INT_MAX, maxNum = INT_MIN;
        for(int& n:nums){
            minNum = min(n, minNum);
            maxNum = max(n, maxNum);
        }
        // init data structure to store the pair(min,max) in different bins
        int minGap = ceil((double)(maxNum-minNum)/(nums.size()-1));
        if(!minGap) return 0;
        int numOfBins = (maxNum-minNum)/minGap+1;
        vector<int> minBins(numOfBins, maxNum);
        vector<int> maxBins(numOfBins, minNum);
        for(auto n:nums){
            int binIdx = (n-minNum)/minGap;
            minBins[binIdx] = min(minBins[binIdx], n);
            maxBins[binIdx] = max(maxBins[binIdx], n);
        }
        // debug helper to display nums
        /*for(int i=0; i<numOfBins; ++i){
            cout<<i<<" "<<minBins[i]<<" "<<maxBins[i]<<endl;
        }*/
        // iterate through all sequential nums to find max gap
        int maxGap = INT_MIN;
        int previous = minNum;
        for(int i=0; i<numOfBins; ++i){
            if(minBins[i] == maxNum && maxBins[i] == minNum)
                continue;
            maxGap = max(minBins[i]-previous, maxGap);
            previous = maxBins[i];
        }
        return maxGap;
    }
};