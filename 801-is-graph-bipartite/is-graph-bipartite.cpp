
    bool isBipertiteDFS(vector<vector<int>> &adj,int current,vector<int> &color, int currentColor)
    {
        if(color[current]==-1)
        {
            color[current] = currentColor;
        }


        for(int &v: adj[current])
        {
            if(color[v]==color[current]) return false;

            if(color[v]==-1)
            { 
                if(!isBipertiteDFS(adj,v,color,1 - color[current])) return false;
            }
        }

        return true;
    }

class Solution {
    public:

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n,-1);

        for(int i=0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(!isBipertiteDFS(graph,i,color,1)) return false;
            }
        }

        return true;
    }
};