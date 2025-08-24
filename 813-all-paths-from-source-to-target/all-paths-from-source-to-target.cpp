class Solution {
public:

    void DFS(vector<vector<int>>& graph,int u,int target,vector<vector<int>> &ans,vector<int> temp)
    {
        temp.push_back(u);
        if(u==target)
        {
            ans.push_back(temp);
            return;
        }

        for(int &v : graph[u])
        {
            DFS(graph,v,target,ans,temp);
        }

        temp.pop_back();

    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> ans;
        vector<int> temp;

        DFS(graph,0,graph.size()-1,ans,temp);
        return ans;
    }
};