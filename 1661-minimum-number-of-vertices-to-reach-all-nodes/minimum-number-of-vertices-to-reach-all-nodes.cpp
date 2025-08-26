class Solution {
public:

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<bool> inDegree(n,0);

        for(auto &vec : edges)
        {
            inDegree[vec[1]] = 1;
        }
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(inDegree[i]==0) ans.push_back(i);
        }

        return ans;

    }
};