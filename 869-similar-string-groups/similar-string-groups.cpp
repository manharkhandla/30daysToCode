class Solution {
public:

    void DFS(vector<vector<int>> &adj,vector<bool> &visited,int curr)
    {
        visited[curr] = 1;

        for(int &v : adj[curr])
        {
            if(!visited[v])
            {
                DFS(adj,visited,v);
            }
        }
    }

    bool isSame(string &s1,string &s2)
    {   
        int maxDifference = 0;

        int s = s1.size();

        for(int i=0;i<s;i++)
        {
            if(s1[i]!=s2[i]) maxDifference++;
        }

        return (maxDifference==2 || maxDifference==0);
    }

    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        vector<vector<int>> adj(n);

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isSame(strs[i],strs[j]))
                {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int ans = 0;

        vector<bool> visited(n,0);

        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                ans++;
                DFS(adj,visited,i);
            }
        }
        
        return ans;
    }
};