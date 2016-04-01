/*
* Use Segment Tree to implement range sum
* refer to http://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
inline int LEFT(int i){
    return i*2+1;
}
inline int RIGHT(int i){
    return i*2+2;
}
class NumArray {
public:
    // build the segment tree recursively
    int buildST(vector<int> &nums, int start, int end, int index){
        // seg size == 1
        if(start == end){
            ST[index] = nums[start];
            return ST[index];
        }
        // cut the seg into halves and recursively build the tree
        int mid = start+(end-start)/2;
        ST[index] = buildST(nums, start, mid, LEFT(index)) + buildST(nums, mid+1, end, RIGHT(index));
        return ST[index];
    }
    NumArray(vector<int> &nums) {
        size = nums.size();
        if(nums.empty())    return;
        int h = (int)(ceil(log2(size))); 
        ST.resize(2*(int)pow(2, h) - 1);
        buildST(nums, 0, size-1, 0);
    }

    void addToRange(int start, int end, int index, int i, int diff){
        // update current node
        ST[index] += diff;
        // arrive the bottom
        if(start == end)  return;  
        // update left or right node
        int mid = start + (end-start)/2;
        if(i <= mid)    addToRange(start, mid, LEFT(index), i, diff);
        else    addToRange(mid+1, end, RIGHT(index), i, diff);
    }
    void update(int i, int val) {
        if(i<0 || i>=size)  return;
        int diff = val - sumRange(i,i);
        addToRange(0, size-1, 0, i, diff);
    }
    // query the seg tree within range l to r
    // 1. if range of node is within l,r return value of node
    // 2. if range of node is outside l,r return 0
    // 3. return left node + right node
    int query(int start, int end, int index, int l, int r){
        if(l>end || r<start)    return 0;
        if(start>=l && end <= r)    return ST[index];
        int mid = start+(end-start)/2;
        return query(start, mid, LEFT(index), l, r) + query(mid+1, end, RIGHT(index), l, r);
    }
    int sumRange(int i, int j) {
        if(i>j || i<0 || j>size)    return 0;
        return query(0, size-1, 0, i, j);
    }

    // helper function for debug
    void printST(){
        for(auto &i:ST) cout<<i<<" ";
    }
private:
    int size;
    vector<int> ST;   // represent segment tree
};

int main(){
    
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};//, 11, 12, 13, 14};
    NumArray na(nums);
    cout<<na.sumRange(0,2)<<endl;
    na.update(1,5);
    cout<<na.sumRange(0,2)<<endl;
    

}
// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);