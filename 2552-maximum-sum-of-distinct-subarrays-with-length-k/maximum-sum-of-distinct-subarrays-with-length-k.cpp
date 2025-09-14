#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long ans = 0;
        long long sum = 0;
        int i = 0, j = 0;

        unordered_set<int> st;

        while (j < n)
        {
        
            if (st.count(nums[j]) == 0)
            {
                st.insert(nums[j]);
                sum += nums[j];
            } 
            
            else 
            {
                while (st.count(nums[j])) 
                {
                    st.erase(nums[i]);
                    sum -= nums[i];
                    i++;
                }
                st.insert(nums[j]);
                sum += nums[j];
            }

            if (j - i + 1 == k) 
            {
                ans = max(sum, ans);
                sum -= nums[i];
                st.erase(nums[i]);
                i++;
            }

            j++;
        }

        return ans;
    }
};
