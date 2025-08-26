class Solution {
public:
    
    void DFS(vector<vector<int>>& adj,int current,int &count,vector<bool> &visited)
    {
        visited[current] = 1;

        for(int &v : adj[current])
        {
            if(!visited[v])
            {
                DFS(adj,v,count,visited);
                count++;
            }
        }
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;

                long long ux = bombs[i][0];
                long long uy = bombs[i][1];
                long long ur = bombs[i][2];

                long long vx = bombs[j][0];
                long long vy = bombs[j][1];

                long long dx = vx - ux;
                long long dy = vy - uy;

                long long distSq = dx*dx + dy*dy;
                long long range = ur * ur;

                if(distSq <= range) adj[i].push_back(j);
            }
        }

        int ans = 1;
        for(int i=0;i<n;i++)
        {
            int count = 1;
            vector<bool> visited(n,0);
            DFS(adj,i,count,visited);
            ans = max(ans,count);
        }

        return ans;
    }
};