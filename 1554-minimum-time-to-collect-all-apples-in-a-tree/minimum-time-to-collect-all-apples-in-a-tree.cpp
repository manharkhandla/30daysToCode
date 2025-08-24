class Solution {
public:

    int DFS(vector<vector<int>>& adj,vector<bool> &hasApple,int u,int parent)
    {
        int time = 0;

        for(int &child : adj[u])
        {
            if(child == parent) continue;

            int childTime = DFS(adj,hasApple,child,u);

            if(childTime>0 || hasApple[child]) time+= childTime + 2;
        }

        return time;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);

        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int time = DFS(adj,hasApple,0,-1);
        return time;
    }
};