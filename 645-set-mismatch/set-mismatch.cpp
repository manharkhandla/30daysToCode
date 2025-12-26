class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        int expectSum = n*(n+1)/2;
        int totalSum = 0;

        for(int i=0;i<n;i++) totalSum += nums[i];
        int duplicate = -1;

        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                duplicate = nums[i];
                break;
            }
        }

        vector<int> ans(2,-1);
        ans[0] = duplicate;
        ans[1] = duplicate + (expectSum - totalSum);

        return ans;

    }
};