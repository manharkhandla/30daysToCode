class Solution {
public:
    void DFS(vector<int>& edges,int node,vector<bool> &visited,vector<int> &dist)
    {
        visited[node]=1;

        int v = edges[node];

        if(v!=-1 &&  !visited[v] )
        {
            visited[v] = 1;
            dist[v] = dist[node] + 1;
            DFS(edges,v,visited,dist);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();

        vector<int> dist1(n,INT_MAX);
        dist1[node1] = 0;
        vector<int> dist2(n,INT_MAX);
        dist2[node2] = 0;

        vector<bool> visited1(n,0);
        vector<bool> visited2(n,0);

        DFS(edges,node1,visited1,dist1);
        DFS(edges,node2,visited2,dist2);

        
        int minDistNode = -1;
        int minDsTillNow = INT_MAX;

        for(int i=0;i<n;i++)
        {
            int maxm = max(dist1[i],dist2[i]);
            
            if(minDsTillNow > maxm)
            {
                minDsTillNow = maxm;
                minDistNode = i;
            }
        }

        
        return minDistNode;

    }
};