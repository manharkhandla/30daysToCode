class Solution {
public:

    void DFS(unordered_map<char, vector<char>> &adj,vector<bool> &visited,char u,char &best)
    {
        if (visited[u - 'a']) return;
        visited[u - 'a'] = true;

        
        if (u < best) best = u;

        for (char v : adj[u])
        {
            DFS(adj, visited, v, best);
        }
    }


    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size();

        int m = baseStr.size();

        unordered_map<char, vector<char>> adj;

        for(int i=0;i<n;i++)
        {
            char u = s1[i];
            char v = s2[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        for(int i=0;i<m;i++)
        {
            vector<bool> visited(26,0);
            char best = baseStr[i];
            DFS(adj, visited, baseStr[i], best);
            baseStr[i] = best;
        }

        return baseStr;
    }
};