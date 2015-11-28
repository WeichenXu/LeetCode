class Solution {
public:
    string insertSep(string s){
        string result="";
        for(int i=0; i<s.length(); i++){
            result.append("#").append(s,i,1);
            if(i == s.length()-1)   result+="#";
        }
        //cout<<result<<endl;
        return result;
    }
    string longestPalindrome(string s) {
        string ss = insertSep(s);
        int c=0,r=0,maxPindex,maxP=-1;
        int p[ss.length()]={0};
        for(int i=1; i<ss.length(); i++){
            if(i<=r && p[c+c-i] < r-i){
                p[i] = p[c+c-i];
            }
            else{   // i is out of range
                int i_p=1;
                i_p = r>=i_p+i?r-i:i_p;
                while((i+i_p)<ss.length() && (i-i_p) >=0 && ss[i+i_p] == ss[i-i_p]){
                    i_p++;
                }
                i_p--;
                p[i] = i_p;
                c=i;
                r=i+i_p; 
            }
        }
        for(int i=0; i<ss.length(); i++){
            if(p[i] > maxP){
                maxP = p[i];
                maxPindex = i;
            }
        }
        return maxP>=0?s.substr((maxPindex-maxP)/2, maxP):s;
    }
};