class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if(!denominator || !numerator)    return "0";
        string res;
        if(numerator<0 ^ denominator<0) res+="-";
        long int n = labs(numerator), d = labs(denominator);
        res += to_string(n/d);
        n = n%d;
        if(!n) return res;
        res += "."; // append decimal
        map<unsigned int, unsigned int> remainderTable;
        while(n){
            n *= 10;
            if(remainderTable.find(n) != remainderTable.end()){
                // find the repeat circle
                res.insert(remainderTable[n], 1, '(');
                res.append(1, ')');
                break;
            }
            res += to_string(n/d);
            remainderTable[n] = res.length()-1;
            n = n%d;
        }
        return res;
    }
};