class Solution {
public:
    typedef pair<int,int> P;
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<bool> visited(n,0);

        priority_queue<P,vector<P>,greater<P>> pq;

        for(int i=0;i<n;i++) pq.push({nums[i],i});
        
        long long ans = 0;

        while(!pq.empty())
        {
            P temp = pq.top();
            int element = temp.first;
            int idx = temp.second;
            pq.pop();

            if(!visited[idx])
            {
                visited[idx]=1;
                ans+=element;

                if(idx-1>=0 && !visited[idx-1]) visited[idx-1]=1;
                if(idx+1<n && !visited[idx+1]) visited[idx+1]=1;
            }      
        }

        return ans;
    }
};