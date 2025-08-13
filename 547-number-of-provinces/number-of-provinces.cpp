class Solution {
public:

    void DFS(vector<vector<int>> &isConnected,vector<bool> &visited,int city)
    {
        if(visited[city]) return;
        visited[city] = 1;

        for(int &v : isConnected[city])
        {
            if(!visited[v])
            {
                DFS(isConnected,visited,v);
            }
        }

        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();

        vector<bool> visited(n,0);

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) isConnected[i][j] = 0;
                if(isConnected[i][j]==1)
                {
                    isConnected[i][j] = j;
                }
            }
        }

        int ans = 0;

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans++;
                DFS(isConnected,visited,i);
            }
        }

        return ans;
    }
};