class Solution {
public:

    void DFS(vector<vector<pair<int,bool>>> &adj,int curr,int &ans,vector<bool> &visited)
    {
        if(visited[curr]) return;
        visited[curr] = 1;

        for(auto &vec : adj[curr])
        {
            int v = vec.first;
            bool isReal = vec.second;

            if(!visited[v])
            {
                if(isReal) ans++;
                DFS(adj,v,ans,visited);
            }
        }
    }

    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,bool>>> adj(n);

        for(auto &vec : connections)
        {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(make_pair(v,1));
            adj[v].push_back(make_pair(u,0));
        }

        int ans = 0;
        vector<bool> visited(n,0);

        DFS(adj,0,ans,visited);

        return ans;
    }
};