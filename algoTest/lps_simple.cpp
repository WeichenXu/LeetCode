class Solution {
public:
    string insertSep(string s){
        string result="";
        result.append(1, '$');
        for(int i=0; i<s.length(); i++){
            result.append("#").append(s,i,1);
            if(i == s.length()-1)   result+="#";
        }
        result.append(1, '?');
        //cout<<result<<endl;
        return result;
    }
    string longestPalindrome(string s) {
        string ss = insertSep(s);
        int p[ss.length()+1] = {0};
        int id = 0, max = 0, maxId = 0;
        for(int i=1; i<ss.length()-1; i++){
            p[i] = max>i?min(p[2*id-i], max-i):1;
            while(ss[i-p[i]] == ss[i+p[i]]) p[i]++;
            if(i+p[i] > max){
                id = i;
                max = i+p[i];
            }
        }
        max = 0;
        for(int i=1; i<ss.length()-1; i++){
            if(p[i] > max){
                maxId = i;
                max = p[i];
            }
        }
        maxId = (maxId-1)/2;
        return s.substr(maxId-(max-1)/2, max-1);
    }
};