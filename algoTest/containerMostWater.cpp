class Solution {
public:
    int maxArea(vector<int>& height) {
        int size = height.size();
        int max = 0,i=0,j=size-1,temp;
        while(i<j){
            if(height[i]>height[j]){
                temp = height[j]*(j-i);
                j--;
            }
            else{
                temp = height[i]*(j-i);
                i++;
            }
            max = max>temp?max:temp;
        }
        return max;
    }
};