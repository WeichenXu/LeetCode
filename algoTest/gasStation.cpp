class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int stations = gas.size();
        int start = stations-1, end = 0;
        int sum = gas[start]-cost[start];
        while(end < start){
            if(sum > 0){
                sum += gas[end]-cost[end];
                ++end;
            }
            else{
                --start;
                sum += gas[start]-cost[start];
            }
        }
        return sum >=0 ?start:-1;
    }
};