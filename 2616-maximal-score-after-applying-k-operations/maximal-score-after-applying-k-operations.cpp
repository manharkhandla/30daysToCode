class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int n = nums.size();

        for(int i=0;i<n;i++) pq.push(nums[i]);
        long long ans = 0;

        while(k--)
        {
            int maxNum = pq.top();
            pq.pop();
            ans+=maxNum;
            pq.push((int)ceil(maxNum / 3.0));
        }

        return ans;
    }
};