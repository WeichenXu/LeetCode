class TwoSum {
public:

    // Add the number to an internal data structure.
	void add(int number) {
	    nums[number]++;
	}

    // Find if there exists any pair of numbers which sum is equal to the value.
	bool find(int value) {
	    for(unordered_map<int, int>::iterator it = nums.begin(); it != nums.end(); it++){
	        int i = it->first, j = value-i;
	        if((i==j && it->second > 1) || (i!=j && nums.find(j) != nums.end()))    return true;
	    }
	    return false;
	}
private:
    unordered_map<int, int> nums;
};


// Your TwoSum object will be instantiated and called as such:
// TwoSum twoSum;
// twoSum.add(number);
// twoSum.find(value);