class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ans = nums[0];
        int count = 1;

        for(int i=1;i<n;i++)
        {
           if(nums[i]==ans || count==0)
           {
                count++;
                ans = nums[i];
           }
           else count--;
        }
         
        return ans;

    }
};