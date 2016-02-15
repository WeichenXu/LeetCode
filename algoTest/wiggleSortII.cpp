class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        // find the median in constant time
        if(nums.empty()) return;
        int n = nums.size();
        nth_element(nums.begin(), nums.begin()+n/2, nums.end());
        int median = nums[n/2];
        cout<<median<<endl;
        // re-wire index
        #define A(i) nums[(i*2+1)%(n|1)]
        
        // three-way-partition
        int i=0, j=0, k=n-1;
        while (j<=k){
            if(A(j) > median)   swap(A(i++), A(j++));
            else if(A(j) < median)  swap(A(j), A(k--));
            else j++;
        }
    }
};