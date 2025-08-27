class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int,double>>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            double d = succProb[i];

            adj[u].push_back({v,d});
            adj[v].push_back({u,d});
        }

        vector<double> result(n,0);
        result[start_node] = 1.0;
        priority_queue<pair<double,int>> q;
        q.push({1.0,start_node});

        while(!q.empty())
        {
            int node = q.top().second;
            double prob = q.top().first;
            q.pop();

            if(node == end_node) return prob;

            for(auto &vec : adj[node])
            {
                int v = vec.first;
                double pv = vec.second;

                if(pv*prob > result[v])
                {
                    result[v] = pv*prob;
                    q.push({pv*prob,v});
                }
            }
        }


        return result[end_node];
    }
};