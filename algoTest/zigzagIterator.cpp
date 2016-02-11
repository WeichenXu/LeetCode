class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        myV1 = v1;
        myV2 = v2;
        cur = -1;
        smallSize = min(v1.size(), v2.size());
    }

    int next() {
        int res;
        cur++;
        if(cur/2 < smallSize){
            if(cur%2) res = myV2[cur/2];
            else res = myV1[cur/2];
        }
        else res = myV1.size()>myV2.size()?myV1[cur-smallSize]:myV2[cur-smallSize];
        
        return res;
    }

    bool hasNext() {
        if(cur+1<(myV1.size()+myV2.size())){
            return true;
        }
    }
private:
    int cur, smallSize;
    vector<int> myV1;
    vector<int> myV2;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */