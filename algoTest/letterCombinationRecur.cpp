class Solution {
public:
    void generator(string &digits, int index, vector<string> &combinations, string &curStr, string numberMap[]){
        if(index == digits.length())  {
            combinations.push_back(curStr);
            return;
        }
        int curDigit = digits[index] - '0';
        for(int i=0; i<numberMap[curDigit].length(); i++){
            curStr.append(1, numberMap[curDigit][i]);
            generator(digits, index+1, combinations, curStr, numberMap);
            curStr.resize(curStr.length()-1);
        }
        
    }
    vector<string> letterCombinations(string digits) {
        string numberMap[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> combinations;
        string curStr = "";
        if(!digits.length()) return combinations;
        generator(digits, 0, combinations, curStr, numberMap);
        return combinations;
    }
};