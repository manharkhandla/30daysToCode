class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        vector<long long> ans(n, 0);

        vector<array<int,3>> arr;
        for (int i = 0; i < n; i++) 
        {
            arr.push_back({nums1[i], nums2[i], i});
        }

        sort(arr.begin(), arr.end());

        priority_queue<int, vector<int>, greater<int>> pq;
        long long sum = 0;

        for (int i = 0; i < n; i++) 
        {
            auto [val1, val2, originalIdx] = arr[i];

            if(i>0 && arr[i-1][0]==val1) ans[originalIdx] = ans[arr[i-1][2]];
            else ans[originalIdx] = sum;

            pq.push(val2);
            sum += val2;
            if (pq.size() > k) 
            {
                sum -= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};
