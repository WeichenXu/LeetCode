class Solution {
public:
    int findNextNum(string &version, size_t &index){
        if(index >= version.length()) return 0;
        int res;
        size_t find = version.find('.', index);
        if(find == string::npos){
             res = stoi(version.substr(index, version.length()-index));
             index = version.length()+1;
        }
        else 
        {
            res =  stoi(version.substr(index, find-index));
            index = find+1;
        }
        return res;
    }
    int compareVersion(string version1, string version2) {
        size_t tmp1=0, tmp2=0;
        while(1){
            int v1 = findNextNum(version1, tmp1);
            int v2 = findNextNum(version2, tmp2);
            if(v1 > v2) return 1;
            if(v1 < v2) return -1;
            if(tmp1>version1.length() && tmp2>version2.length()) return 0;
        }
    }
};