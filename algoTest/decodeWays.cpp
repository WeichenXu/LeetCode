class Solution {
public:
    int numDecodings(string s) {
        int nums[s.length()+1];
        nums[0] = 1;
        for(int i=0; i<s.length(); ++i){
            nums[i+1] = 0;
            // the single digit case
            if(!i){
                int oDigit = s[i]-'0';
                if(!oDigit) return 0;
                else nums[i+1] = 1;
            }
            // two digit case
            else{
                int oDigit = s[i]-'0';
                int tDigit = s[i]-'0'+10*(s[i-1]-'0');
                if(!oDigit && (tDigit<10 || tDigit>26)) return 0;
                if(oDigit)  nums[i+1] += nums[i];
                if(tDigit>=10 && tDigit<=26)    nums[i+1] += nums[i-1];
            }
        }
        return s.length()?nums[s.length()]:0;
    }

};