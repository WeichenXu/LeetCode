class Solution {
public:
    string multiply(string num1, string num2) {
        //if(num1.length() == 0 || num2.length() == 0)
        string res(num1.length()+num2.length()+1, '0');
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        for(int i=0; i<num1.length(); i++){
            int digit1 = num1[i] - '0';
            int carry = 0;
            for(int j=0; j<num2.length(); j++){
                int digit2 = (num2[j]-'0')*digit1+(res[i+j]-'0')+carry;
                //cout<<digit2<<endl;
                carry = digit2/10;
                res[i+j] = digit2%10+'0';
            }
            res[i+num2.length()] = carry + '0';
        }
        reverse(res.begin(), res.end());
        // remove zeros
        int i=0;
        while(i<res.length()-1 && res[i] == '0') i++;
        res.erase(0, i);
        return res;
    }
};