class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for(int i=0;i<n;i++) pq.push(nums[i]);
        int ans = 0;

        while(pq.size()>=2 && pq.top()<k)
        {
            long long min1 = pq.top();
            pq.pop();
            long long min2 = pq.top();
            pq.pop();
            pq.push(min1*2 + min2);
            ans++;
        }

        return ans;
    }
};