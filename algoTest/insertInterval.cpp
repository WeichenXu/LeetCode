class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> result;
        Interval cur;
        int i=0;
        bool inserted = false;
        while(i<intervals.size() || !inserted){
            if(inserted || (i<intervals.size()&&intervals[i].start < newInterval.start)){
                cur = intervals[i];
                i++;
            }
            else{
                inserted = true;
                cur = newInterval;
            }
            if(result.empty() || result.back().end<cur.start){
                result.push_back(cur);
            }
            else{
                result.back().end = max(result.back().end, cur.end);
            }
        }
        return result;
    }
};