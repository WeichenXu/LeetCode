class Solution {
public:
    string getBaseDiff(string &str){
        char base;
        string res = "a";
        for(int i=0; i<str.length(); i++){
            if(!i) base = str[0];
            else{
                res.append(1, 'a'+(str[i]-base<0?str[i]+26-base:str[i]-base));
            }
        }
        return res;
    }
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, int> shifts;
        vector<vector<string>> res;
        sort(strings.begin(), strings.end());
        for(int i=0; i<strings.size(); i++){
            string baseDiff = getBaseDiff(strings[i]);
            if(shifts.find(baseDiff) == shifts.end()){
                // add the new shift into dic
                shifts[baseDiff] = res.size();
                vector<string> newShift;
                res.push_back(newShift);
            }
            // add the string to corresponding shift
            res[shifts[baseDiff]].push_back(strings[i]);
        }
        return res;
    }
};