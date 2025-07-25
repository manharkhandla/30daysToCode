class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        bool isDup;

        for(int i=0;i<n;i++)
        {
            isDup = false;
            for(int j=0;j<n;j++)
            {
                if(i==j) continue; 
                if(nums[i]==nums[j])
                {
                    isDup = true;
                }
            }
            if(!isDup)
            {
                sum += nums[i];
            }
        }

        return sum;
    }
};