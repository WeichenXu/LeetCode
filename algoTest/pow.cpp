class Solution {
public:
    double myPow(double x, int n) {
        double result = 1.0, tmp = x;
        int digits = 0;
        bool pos = false;
        if(n >= 0) pos = true;
        n = abs(n);
        //while((1<<digits) <= n) digits++;
        
        for(int i=0; i<32; i++){
            //cout<<result<<endl;
            if((1<<i) & n){
               if(pos)    result *= tmp; 
               else result *= (1.0/tmp);
            }
            tmp *= tmp;
        }
        return result;
    }
};