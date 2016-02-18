/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<pair<int, int>> changes;
        for(auto interval:intervals){
            changes.push_back(make_pair(interval.start, 1));
            changes.push_back(make_pair(interval.end, -1));
        }
        sort(changes.begin(), changes.end());
        int maxRoom = 0, room = 0;
        for(auto change:changes){
            maxRoom = max(maxRoom, room+=change.second);
        }
        return maxRoom;
    }
};