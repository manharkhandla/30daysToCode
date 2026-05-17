class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        
        int n = arr.size();

        vector<bool> visited(n,0);
        visited[start] = 1;

        queue<int> q;

        q.push(start);

        while(!q.empty())
        {
            int index = q.front();
            q.pop();
            visited[index] = 1;

            if(arr[index]==0) return true;

            int newIdx1 = index + arr[index];
            int newIdx2 = index - arr[index];

            if(newIdx1 < n && !visited[newIdx1])
            {
                visited[newIdx1] = 1;
                q.push(newIdx1);
            } 
            
            if(newIdx2 >= 0 && !visited[newIdx2])
            {
                visited[newIdx2] = 1;
                q.push(newIdx2);
            } 
        }

        return false;

    }
};