class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int mx = -1;

        for(int i=0;i<n1;i++)
        {
            if(nums1[i]>mx) mx=nums1[i];
        }

        vector<bool> present(mx+1,0);
        for(int i=0;i<n1;i++) present[nums1[i]]=1;
        vector<int> ans;

        for(int i=0;i<n2;i++)
        {
            if(present[nums2[i]])
            {
                ans.push_back(nums2[i]);
                present[nums2[i]]=0;
            }
        }

        return ans;
    }
};