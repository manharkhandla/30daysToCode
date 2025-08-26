class Solution {
public:

    void DFS(unordered_map<string,vector<pair<string,double>>> &adj,string src,string des,unordered_set<string> &visited,double product, double &res)
    {
        if(visited.find(src) != visited.end()) return;

        visited.insert(src);

        if(src==des)
        {
            res = product;
            return;
        }

        for(auto &p : adj[src])
        {
            string v = p.first;
            double div = p.second;

            DFS(adj,v,des,visited,product*div,res);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        int n = equations.size();

        unordered_map<string,vector<pair<string,double>>> adj;

        for(int i=0;i<n;i++)
        {
            string u = equations[i][0];
            string v = equations[i][1];
            double div = values[i];

            adj[u].push_back({v,div});
            adj[v].push_back({u,1.0/div});
        }

        vector<double> ans;

        for(int i=0;i<queries.size();i++)
        {
            string source = queries[i][0];
            string dest = queries[i][1];

            double res = -1.0;
            double pro = 1.0;

            if(adj.find(source) != adj.end())
            {
                unordered_set<string> visited;
                DFS(adj,source,dest,visited,pro,res);
            }

            ans.push_back(res);
        }

        return ans;
    }
};