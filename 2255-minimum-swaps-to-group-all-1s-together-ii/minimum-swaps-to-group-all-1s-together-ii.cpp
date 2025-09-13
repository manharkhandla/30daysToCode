class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int totalOne = 0;
        for(int i=0;i<n;i++) if(nums[i]==1) totalOne++;

        int j=0,i=0;
        int sum=0;
        int ans=n;
        while(j<2*n)
        {
            sum+=nums[j%n];

            if (j - i + 1 > totalOne)
            {
                sum -= nums[i % n];
                i++;
            }

            if (j - i + 1 == totalOne)
            {
                ans = min(ans, totalOne - sum);
            }
            j++;
        }

        return ans;
    }
};