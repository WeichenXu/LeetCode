class Solution {
public:
    string convert(string s, int numRows) {
        //char res[s.length()];
        string res;
        int j=2*numRows-2,m;
        for(int i=0; i<numRows; i++){
            m=0;
            while(m < s.length()){
                if(!i || i == numRows-1)  {
                    if(m+i<s.length())  {
                        res.push_back(s[m+i]);
                    }
                }
                else{
                    if(m+i<s.length())  {
                        res.push_back(s[m+i]);
                    }
                    if(m+j-i<s.length()){
                        res.push_back(s[m+j-i]); 
                    }
                    
                }
                if(j>0) m += j;
                else    m+=numRows;
            }
        }
        return res;
    }
};