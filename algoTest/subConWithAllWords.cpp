class Solution {
public:
    unordered_map<string, int> getWordsMap(vector<string>& words){
        unordered_map<string, int> wordsMap;
        for(int i=0; i<words.size(); i++){
            if(wordsMap.find(words[i]) == wordsMap.end()){
                wordsMap[words[i]] = 1;
            }
            else    wordsMap[words[i]] ++;
        }
        return wordsMap;
    }
    void findSubstringWithIndex(string s, int wordSize, int index, unordered_map<string, int>& words, int matchSize, vector<int> &match){
        int i=index, j=i, curSubSize=0;
        string curSubstr;
        //cout<<j<<" "<<(int)(s.length() - wordSize)<<endl;
        while(j <= (int)(s.length() - wordSize)){
            curSubstr = s.substr(j, wordSize);
            //cout<<curSubstr<<" "<<curSubSize<<endl;
            if(words.find(curSubstr) == words.end()){
                j+=wordSize;
                curSubSize = 0;
                while(i<j){
                    if(words.find(s.substr(i,wordSize)) != words.end()) words[s.substr(i,wordSize)]++;
                    i+= wordSize;
                }
            }
            else if(words[curSubstr] == 0){
                words[s.substr(i,wordSize)]++;
                curSubSize--;
                i+=wordSize;
            }
            else{
                words[curSubstr]--;
                curSubSize++;
                //cout<<curSubSize<<" "<<matchSize<<endl;
                if(curSubSize == matchSize){
                    match.push_back(i);
                    curSubSize--;
                    words[s.substr(i, wordSize)]++;
                    i+=wordSize;
                }
                j += wordSize;
            }
        }
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string, int> wordsMap;
        int wordSize;
        if(words.empty())   return result;
        wordSize = words[0].length();
        for(int i=0; i<wordSize; i++){
            wordsMap = getWordsMap(words);
            findSubstringWithIndex(s, wordSize, i, wordsMap, words.size(), result);
        }
        return result;
    }
};