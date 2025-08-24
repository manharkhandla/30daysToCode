class Solution {
public:

    void DFS(vector<bool> &visited,vector<vector<int>> &adj,int &count,int i)
    {
        if(visited[i]) return;
        visited[i] = 1;

        for(int &v : adj[i])
        {
            if(!visited[v])
            {
                DFS(visited,adj,count,v);
            }
        }
    }

    int removeStones(vector<vector<int>>& stones) {
        int V = stones.size();
        vector<vector<int>> adj(V);
        vector<bool> visited(V,0);

        for(int i=0;i<V;i++)
        {
            for(int j=i+1;j<V;j++)
            {
                if(stones[j][0]==stones[i][0] || stones[j][1]==stones[i][1])
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int count = 0;

        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                DFS(visited,adj,count,i);
                count++;
            }       
        }

        return (V-count);
    }
};