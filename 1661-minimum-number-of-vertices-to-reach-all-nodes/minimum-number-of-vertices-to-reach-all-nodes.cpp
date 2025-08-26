class Solution {
public:

    void DFS( vector<vector<int>> &adj,vector<bool> &visited,int curr,stack<int> &s,bool push)
    {
        visited[curr] = 1;

        for(int &v : adj[curr])
        {
            if(!visited[v]) DFS(adj,visited,v,s,push);
        }

        if(push) s.push(curr);
    }

    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
        }

        vector<bool> visited(n,0);
        vector<int> ans;
        stack<int> s;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                DFS(adj,visited,i,s,1);
            }
        }

        fill(visited.begin(), visited.end(), 0);
        int m = s.size();

        for(int i=0;i<m;i++)
        {
            int node = s.top();
            s.pop();
            if(!visited[node])
            {
                DFS(adj,visited,node,s,0);
                ans.push_back(node);
            }
        }

        return ans;
    }
};