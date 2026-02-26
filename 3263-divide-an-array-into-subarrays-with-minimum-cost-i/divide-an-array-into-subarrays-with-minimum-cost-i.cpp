class Solution {
public:
    int minimumCost(vector<int>& nums) {
        
        int ans = nums[0];

        int n = nums.size();
        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for(int i=1;i<n;i++)
        {
            if(nums[i]<=smallest)
            {
                secondSmallest = smallest;
                smallest = nums[i];   
            }
            else if(nums[i] < secondSmallest)
            {
                secondSmallest = nums[i];
            }
        } 

        ans = ans + smallest + secondSmallest;

        return ans;

    }
};