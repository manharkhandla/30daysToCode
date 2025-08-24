class Solution {
public:

    void DFS(vector<vector<int>> &adj,vector<bool> &visited,int source)
    {
        if(visited[source]) return;
        visited[source] = 1;

        for(int &v : adj[source])
        {
            if(!visited[v]) DFS(adj,visited,v);
        }

        return;
    }

    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<bool> visited(n,0);

        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int vertex = edges[i][0];
            adj[vertex].push_back(edges[i][1]);

            int vertex2 = edges[i][1];
            adj[vertex2].push_back(edges[i][0]);
        }

        DFS(adj,visited,source);
        if(visited[destination]) return true;
        return false;
    }
};