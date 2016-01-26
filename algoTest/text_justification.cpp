class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<int> groups;
        vector<int> lineWs;
        vector<string> res;
        int tmp=0, j=0, i=0, lineWLen = 0;
        while(i<words.size()){
            if(((i+j)<words.size()) &&( !j || ((maxWidth - tmp) > words[i+j].length()))){
                if(j)   tmp += (words[i+j].length()+1);
                else tmp += (words[i+j].length());
                //res.push_back(to_string(tmp));
                lineWLen += words[i+j].length();
                j++;
            }
            else{
                groups.push_back(j);
                lineWs.push_back(lineWLen);
                lineWLen = 0;
                tmp = 0;
                i += j;
                j = 0;
            }
        }
        //j = 0;
        for(i=0; i<lineWs.size()-1; i++){
            res.push_back(makeFormat(words, lineWs[i], j, groups[i], false, maxWidth));
            
            j += groups[i];
        }
        
        res.push_back(makeFormat(words, lineWs[i], j, groups.back(), true, maxWidth));
        return res;
    }
    string makeFormat(vector<string>& words, int lineW, int index, int size, bool final, int maxLen){
        string line = "";
        if(!final){
            int gaps = size - 1, tmp=0;
            int blanks = maxLen - lineW;
            int gap = gaps == 0?blanks:blanks/gaps;
            line += words[index];
            for(int i=1; i<size; i++){
                if(tmp < (blanks - gap*gaps)){
                    line.append(gap+1, ' ');
                    tmp++;
                }
                else line.append(gap, ' ');
                line += words[index+i];
            }
        }else{
            line += words[index];
            for(int i=1; i<size; i++){
                line.append(1, ' ');
                line += words[index+i];
            }
        }
        line.append(maxLen-line.length(), ' ');
        return line;
    }
    
};