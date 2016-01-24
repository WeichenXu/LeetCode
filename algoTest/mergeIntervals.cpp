class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<int> starts, ends;
        vector<Interval> merged;
        int i=0, j=0, tmp=0;
        int tmp_start;
        for(int i=0; i<intervals.size(); i++){
            starts.push_back(intervals[i].start);
            ends.push_back(intervals[i].end);
        }
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        while(1){
            if(i < starts.size() && starts[i] <= ends[j]){
                if(tmp == 0) tmp_start = starts[i];
                i++;
                tmp++;
            }
            else{
                j++;
                tmp--;
            }
            if(tmp == 0){
                Interval add(tmp_start, ends[j-1]);
                merged.push_back(add);
            }
            if(i >= starts.size() && j >= ends.size()) break;
        }
        return merged;
    }
};