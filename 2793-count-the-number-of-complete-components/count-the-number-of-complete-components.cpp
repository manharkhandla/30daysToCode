class Solution {
public:

    void dfs(unordered_map<int, vector<int>> &mp, vector<bool> &visited, int &v, int &e, int i)
    {
        visited[i] = 1;

        v++;
        e += mp[i].size();

        for (int x : mp[i])
        {
            if(!visited[x]) dfs(mp,visited,v,e,x);
        }

        return;

    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) 
        {
            mp[i] = vector<int>();
        }

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<bool> visited(n,0);
        int ans = 0;

        for(int i=0;i<n;i++)
        {
            if(visited[i]) continue;

            int v = 0;
            int e = 0;

            dfs(mp,visited,v,e,i);

            if(v*(v-1)/2 == e/2) ans++;
        }

        return ans;

    }
};