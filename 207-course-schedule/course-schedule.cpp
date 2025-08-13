class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> inDegree(numCourses,0);
        queue<int> q;

        for(auto &vec : prerequisites)
        {
            int a = vec[0];
            int b = vec[1];

            adj[b].push_back(a);

            inDegree[a]++;
        }

        int count = 0;


        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0)
            {
                q.push(i);
                count++;
            }
        }

        while(!q.empty())
        {
            int currentCourse = q.front();
            q.pop();
            

            for(int &v : adj[currentCourse])
            {
                inDegree[v]--;
                if(inDegree[v]==0)
                {
                q.push(v);
                   count++; 
                } 
            }
        }

        return (count==numCourses);
    }
};