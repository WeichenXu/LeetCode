class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        // no circle in the graph
        vector<int> nodes(n,0); // the parent of tree node i
        for(int i=0; i<n; i++) nodes[i] = i;
        for(auto edge:edges){
            int f = edge.first, s = edge.second;
            while(nodes[f] != f)    f = nodes[f];
            while(nodes[s] != s)    s = nodes[s];
            if(f == s)  return false;
            nodes[s] = f;
        } 
        return edges.size()==n-1;
    }
    
};