class Solution {
public:
    int candy(vector<int>& ratings) {
        // Initialize parameters
        int numOfChildren = ratings.size(), minNumOfCandies = 0;
        vector<int> candies(numOfChildren, 1);
        auto rankCmp = [](const pair<int,int>&a, const pair<int,int>&b){return a.first<b.first;};
        multiset<pair<int,int>, decltype(rankCmp)> line(rankCmp);
        // Insert (rank, index) into the line
        // automatically sorted in ascending order
        for(int i=0; i<ratings.size(); ++i){
            line.insert(make_pair(ratings[i], i));
        }
        // Iterate through the line, update cur to max(neighbors)+1
        for(auto &cur : line){
            int curPos = cur.second;
            //cout<<curPos<<endl;
            if(curPos > 0 && ratings[curPos-1]<ratings[curPos] && candies[curPos-1] >= candies[curPos]){
                candies[curPos] = candies[curPos-1]+1;
            }
            if(curPos < numOfChildren-1 && ratings[curPos+1]<ratings[curPos] && candies[curPos+1] >= candies[curPos]){
                candies[curPos] = candies[curPos+1]+1;
            }
        }
        // Sum the number of candies in the line
        for(auto &i : candies){
            //cout<<i<<endl;
            minNumOfCandies += i;
        }
        return minNumOfCandies;
    }
};