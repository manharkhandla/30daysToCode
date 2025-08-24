class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>> mp;

        for(int i=0;i<dislikes.size();i++)
        {
            int u = dislikes[i][0];
            int v = dislikes[i][1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<int> color(n+1,-1); 

        queue<int> q;
        

        for(int i=1;i<=n;i++)
        {
            if(color[i]==-1)
            {
                q.push(i);
                color[i] = 0;

                while(!q.empty())
                {
                    int curr = q.front();
                    q.pop();

                    for(int &v: mp[curr])
                    {
                        if(color[v]==color[curr])
                        {
                            return false;
                        }

                        if(color[v]==-1)
                        {
                            color[v] = 1-color[curr];
                            q.push(v);
                        }
                    }
                }
            }
        }
        
        return true;
    }
};