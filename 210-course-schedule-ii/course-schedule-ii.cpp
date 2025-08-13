class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        vector<int> inDegree(numCourses,0);
        queue<int> q;
        int count = 0;

        for(auto &vec : prerequisites)
        {
            int a = vec[0];
            int b = vec[1];
            adj[b].push_back(a);
            inDegree[a]++;
        }

        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
                count++;
                ans.push_back(i);
            }
        }


        while(!q.empty())
        {
            int currentCourse = q.front();
            q.pop();

            for(int &v: adj[currentCourse])
            {
                inDegree[v]--;
                if(inDegree[v]==0)
                {
                    q.push(v);
                    count++;
                    ans.push_back(v);
                }
            }
        }

        if(count==numCourses) return ans;
        return {};
    }
};