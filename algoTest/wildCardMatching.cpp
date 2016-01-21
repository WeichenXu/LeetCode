class Solution {
public:
    bool isMatch(string s, string p) {
        bool maps[s.length()+1] = {false};
        //bool star = true;
        int non_stars = 0;
        maps[0] = true;
        for(int i=0; i<s.length(); i++){
            maps[i+1] = false;
        }
        //printMap(maps, s.length()+1);
        for(int i=0; i<p.length(); i++){
            bool maps2[s.length()+1] = {false};
            if(maps[0] && p[i] == '*') maps2[0] = true;
            for(int j=0; j<s.length(); j++){
                if(p[i] != '*'){
                    if(maps[j] && (p[i] == s[j] || p[i] == '?')) maps2[j+1] = true;
                    else if(maps[j+1] && i && p[i-1] == '*' && p[i] == s[j] && j>= non_stars) maps2[j+1] = true;
                    else maps2[j+1] = false;
                    non_stars++;
                }
                else{
                    if(maps[j+1] || maps2[j])  maps2[j+1] = true;
                }
            }
            memcpy(maps, maps2, 1*(s.length()+1));
            //printMap(maps, s.length()+1);
        }
        
        return maps[s.length()];
    }
    void printMap(bool maps[], int n){
        for(int i=0; i<n; i++){
            cout<<maps[i]<<" ";
        }
        cout<<endl;
    }
};