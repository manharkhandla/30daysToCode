class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int count0 = 0;
        int count1 = 0;
        int ans=0;
        int i=0,j=0;

        while(j<n)
        {
            if(s[j]=='0') count0++;
            else count1++;

            while(count1>k && count0>k)
            {
                if(s[i]=='0') count0--;
                else count1--;

                i++;
            }

            ans+=j-i+1;
            j++;
        }

        return ans;
    }
};