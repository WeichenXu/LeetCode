class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(), s.end());
        size_t i=0,j;
        while(i<s.length()){
            j = s.find(' ', i);
            if(j != string::npos){
                reverse(s.begin()+i, s.begin()+j);
            }
            else{
                reverse(s.begin()+i, s.end());
                break;
            }
            i = j+1;
            //cout<<j<<endl;
        }
    }
};