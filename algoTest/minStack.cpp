class MinStack {
public:
    void push(int x) {
        nums.push_back(x);
        if(track.empty() || x<=track.back()){
            track.push_back(x);
        }
    }

    void pop() {
        if(nums.empty()) return;
        if(nums.back() == track.back()){
            nums.pop_back();
            track.pop_back();
        }
        else    nums.pop_back();
    }

    int top() {
        return nums.back();
    }

    int getMin() {
        return track.back();
    }
private:
    vector<int> nums;
    vector<int> track;
    int curMin;
};