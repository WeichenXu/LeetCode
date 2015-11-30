class Solution {
public:
    int reverse(int x) {
        // For int overflow
        // add a$b < a && a$b < b 
        // 
        /*
        long long absX = (long long)x, res=0;
        absX = abs(absX);
        int max = INT_MAX;
        while(absX){
            res *= 10;
            res += absX%10;
            //res = temp;
            absX = absX/10;
        }
        if(res>max) res = 0;
        return x<absX?-res:res;
        */
        long long res = 0,digit;
        while(x){
            digit = x%10;
            res = res*10+digit;
            x = x/10;
        }
        if(res > INT_MAX || res < INT_MIN)  return 0;
        return res;
    }
};