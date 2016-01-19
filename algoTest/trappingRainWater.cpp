class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0, sum1 = 0;
        int i=0, j;
        for(int k=0; k<height.size(); k++){
            sum1 += height[k];
        }
        while(i< height.size()){
            if(i == height.size()-1){
                sum += height[i];
                break;
            }
            j = largerIndex(height, height[i], i+1);
            //cout<<j<<" "<<sum<<endl;
            if(height[j]>height[i]){
                sum += height[i] * (j-i);
                i = j;
            }
            else{
                sum += height[i];
                sum += height[j]*(j-i-1);
                i = j;
            }
            
        }
        return sum-sum1;
    }
    int largerIndex(vector<int>& height, int num, int start){
        int max = 0, maxi;
        for(int i=start; i<height.size(); i++){
            if(height[i] >= num) return i;
            if(height[i] >= max){
                max = height[i];
                maxi = i;
            }
        }
        return maxi;
    }
};