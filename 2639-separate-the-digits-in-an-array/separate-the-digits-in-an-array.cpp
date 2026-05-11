class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        
        int n = nums.size();

        vector<int> ans;

        for(int i=n-1;i>=0;i--)
        {
            int num = nums[i];

            while(num>0)
            {
                int r = num%10;
                num = num/10;
                ans.insert(ans.begin(),r);
            }
        }

        return ans;

    }
};