class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i=0;i<n;i++)
        {
            nums1.push_back(nums2[i]);
        }

        sort(nums1.begin(),nums1.end());

       for(int i=0;i<nums1.size();i++)
       {
            if(nums1[i]==0 && n!=0)
            {
                nums1.erase(nums1.begin()+i);
                n--;
                i--;
            }
       }
        
        return;
    }
};