class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        
        int n = nums.size();

        vector<int> v(n+1,0);

        for(int i=0;i<n;i++)
        {
            int tempSum = 0;
            string tempString = nums[i];

            for(int j=0;j<n;j++)
            {
                if(tempString[j]=='1') tempSum++;
            }

            v[tempSum]++;
        }
        int k = 0;
        for(int i=0;i<n+1;i++) if(v[i]==0) k=i;

        string s = "";

        for(int i = 0; i < k; i++) s += '1';
        

        for(int i = 0; i < n - k; i++) s += '0';
       
        return s;

    }
};