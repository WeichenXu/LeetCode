class Solution {
public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        // contruct a map, and a multiset<string> to keep order
        for(auto &t:tickets){
            tMaps[t.first].insert(t.second);
        }
        dfsEulerPath("JFK");
        reverse(route.begin(), route.end());
        return route;
    }
    void dfsEulerPath(string start){
        while(tMaps.find(start) != tMaps.end() && !tMaps[start].empty()){
            string next = *(tMaps[start].begin());
            tMaps[start].erase(tMaps[start].begin());
            dfsEulerPath(next);
        }
        route.push_back(start);
    }
private:
    unordered_map<string, multiset<string>> tMaps;
    vector<string> route;
};