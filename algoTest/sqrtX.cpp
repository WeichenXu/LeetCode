class Solution {
public:
    int mySqrt(int x) {
        return sqrtInRange(x, 0, x);
    }
    int64_t sqrtInRange(int64_t x, int64_t a, int64_t b){
        if(a == b) return a;
        if(b-a == 1){
            if(x >= b*b) return b;
            else return a;
        }
        int64_t middle = a+(b-a)/2;
        if(x >= middle*middle){
            return sqrtInRange(x, middle, b);
        }
        else return sqrtInRange(x, a, middle);
    }
};