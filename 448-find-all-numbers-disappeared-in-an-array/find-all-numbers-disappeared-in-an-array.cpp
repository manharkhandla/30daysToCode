class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        vector<bool> present(n+1,0);

        for(int i=0;i<n;i++)
        {
            if(!present[nums[i]]) present[nums[i]] = true;
        }

        for(int i=1;i<=n;i++)
        {
            if(!present[i])
            {
                ans.push_back(i);
            }
        }

        return ans;  
    }
};