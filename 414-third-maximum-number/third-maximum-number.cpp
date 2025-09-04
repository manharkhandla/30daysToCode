class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int level = 1;
        int ans = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<ans)
            {
                level++;
                ans=nums[i];
            }
            if(level==3) return ans;
        }

        return nums[n-1];
    }
};