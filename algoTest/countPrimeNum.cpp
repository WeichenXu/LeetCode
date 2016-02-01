class Solution {
public:
    int countPrimes(int n) {
        vector<bool> nums(n, true);
        int i=2, j, count=0;
        while(i*i < n){
            cout<<i<<endl;
            j = 2;
            while(i*j < n){
                nums[i*j] = false;
                j++;
            }
            while(i++){
                if(nums[i]){
                    break;
                }
            }
        }
        for(int i=2; i<n; i++){
            if(nums[i]) count++;
        }
        return count;
    }
    
};