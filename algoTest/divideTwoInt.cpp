class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor || (divisor == -1 && dividend == INT_MIN)) return INT_MAX;
        int shift=0;
        unsigned long dvd = labs(dividend), dvr = labs(divisor), result=0;
        bool positive=true;
        if(dividend >0 && divisor <0 || dividend<0 && divisor>0) positive = false;
        while((dvr<<shift) <= dvd)  shift++;
        while(dvd >= dvr){
            shift--;
            //cout<<shift<<"  "<<(dvr<<shift)<<endl;
            if(dvd >= (dvr<<shift)){
                dvd -= (dvr<<shift);
                result = result | 1<<shift;
            }
            //cout<<dvd<<endl;
        }
        if(positive)    return (int)result;
        else    return (int)-result;
    }
};