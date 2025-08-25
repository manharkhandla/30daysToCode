class Solution {
public:

    void DFS(unordered_map<int,vector<pair<int,int>>> &mp,vector<bool> &visited,int curr,int &ans)
    {
        visited[curr] = 1;

        for(auto &vec : mp[curr])
        {
            int v = vec.first;
            int d = vec.second;

            ans = min(ans,d);
            if(!visited[v])
            {
                
                DFS(mp,visited,v,ans);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        unordered_map<int,vector<pair<int,int>>> mp;


        for(auto &vec : roads)
        {
            int u = vec[0];
            int v = vec[1];
            int d = vec[2];

            mp[u].push_back(make_pair(v,d));
            mp[v].push_back(make_pair(u,d));

        }

        vector<bool> visited(n+1,0);
        int ans = INT_MAX;

        DFS(mp,visited,1,ans);
        return ans;
    }
};