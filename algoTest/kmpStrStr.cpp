class Solution {
public:
    void generateLPS(int *lps, string s){
        int i=1,len=0;
        if(!s.length()) return;
        lps[0] = 0;
        while(i < s.length()){
            if(s[i] == s[len]){
                len++;
                lps[i] = len;
                i++;
            }
            else{
                if(len){
                    len--;
                }
                else{
                    lps[i] = len;
                    i++;
                }
            }
        }
        return;
    }
    int strStr(string haystack, string needle) {
        int lps[needle.length()]; //the longest prefix & suffix
        generateLPS(lps, needle);
        int i=0,j=0,k;
        while(i < int(haystack.length()-needle.length()+1)){
            //cout<<i<<"  "<<j<<endl;
            k=j;
            while(j<needle.length()&&haystack[i+k] == needle[j]){
                k++;j++;
            }
            if(j >= needle.length())  return i;
            if(j)  {
                i += j-lps[j-1];
                j = lps[j-1];
            }
            else i++;
        }
        return -1;
    }
};