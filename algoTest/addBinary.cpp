class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = 0,n = max(a.length(), b.length()), pre = 0;
        int tmp1, tmp2;
        // reverse str
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while(i<n){
            if(i<a.length()) tmp1 = a[i]-'0';
            else tmp1 = 0;
            if(i<b.length()) tmp2 = b[i]-'0';
            else tmp2 = 0;
            tmp1 = (tmp1+tmp2+pre);
            res.append(1,(tmp1%2)+'0');
            pre = tmp1/2;
            i++;
        }
        if(pre!=0) res.append(1, '1');
        // reverse result;
        reverse(res.begin(), res.end());
        return res;
    }
};