class Solution {
public:

    void DFS(unordered_map<int, vector<int>> &mp,vector<bool> &visited,int source)
    {
        if(visited[source]) return;
        visited[source] = 1;

        for(int &v : mp[source])
        {
            if(!visited[v]) DFS(mp,visited,v);
        }

        return;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n,0);

        unordered_map<int,vector<int>> mp;

        for(vector<int> &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        DFS(mp,visited,source);
        if(visited[destination]) return true;
        return false;
    }
};