class Solution {
public:

    void DFS(vector<vector<int>> &adj,vector<bool> &visited,int curr,long long &count)
    {
        if(visited[curr]) return;
        visited[curr] = 1;

        for(int &v : adj[curr])
        {
            if(!visited[v])
            {
                count++;
                DFS(adj,visited,v,count);
            }
        }
    }

    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for(auto &vec : edges)
        {
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        long long totalPair = (1LL * (n - 1) * n) / 2;
        cout<<totalPair<<" ";
        vector<bool> visited(n,0);

        long long intr = 0;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                long long count = 0;
                DFS(adj,visited,i,count);
                cout<<count<<" ";
                intr += ((count)*(count+1))/2;
            }
        }

        cout<<intr;
        long long ans = (totalPair-intr);
        return ans;
    }
};