class Solution {
public:
    string countAndSay(int n) {
        
        string result = "1";
        for(int i=1; i<n; i++){    
            result = getN(result);
            //cout<<i<<" "<<(result)<<endl;
        }
        return result;
        
    }
    string getN(string n){
        string result = "";
        int i=0, count = 0;
        char val='.';
        while(i <= n.length()){
            if(n[i] != val || i == n.length()){
                if(count){
                    result.append(1, '0'+count);
                    result.append(1, val);
                }
                count = 1;
                val = n[i];
            }
            else    count++;
            i++;
        }
        return result;
    }
};