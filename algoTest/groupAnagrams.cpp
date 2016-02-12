class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<int>> groups;
        vector<vector<string>> result;
        sort(strs.begin(), strs.end());
        for(int i=0; i<strs.size(); i++){
            string tmp(strs[i]);
            sort(tmp.begin(), tmp.end());
            if(groups.find(tmp) != groups.end()){
                groups[tmp].push_back(i);
            }
            else{
                vector<int> add;
                add.push_back(i);
                groups[tmp] = add;
            }
        }
        for(unordered_map<string, vector<int>>::iterator it=groups.begin(); it!=groups.end(); it++){
            vector<string> group;
            for(int i = 0; i<it->second.size(); i++){
                group.push_back(strs[it->second[i]]);
            }
            result.push_back(group);
        }
        return result;
    }
};