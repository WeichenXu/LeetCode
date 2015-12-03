class Solution {
public:
    int charMatch(char s, char p){
        if (p == '.')   return 1;
        else return s==p?1:0;
    }
    bool isMatch(string s, string p) {
        int table[s.length()+1][p.length()+1];
        for(int i=0; i<= s.length(); i++){
            for(int j=0; j<=p.length(); j++){
                table[i][j] = 0;
            }
            //cout<<endl;
        }
        table[0][0] = 1;
        
        for(int i=0; i<= s.length(); i++){
            for(int j=1; j<=p.length(); j++){
                if(p[j-1] != '*' && i ){
                    if(table[i-1][j-1]) table[i][j] = charMatch(s[i-1],p[j-1]);
                }
                else if(j-1>0 && p[j-1] == '*'){ // p[j] is * and not the first
                    if(table[i][j-2] || table[i][j-1])   table[i][j] = 1; // zero or one preceding
                    else if(i && charMatch(s[i-1], p[j-2]) && table[i-1][j])  table[i][j] = 1;
                }
            }
        }
        
        
        return table[s.length()][p.length()];
    }
};