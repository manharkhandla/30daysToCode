class Solution {
public:
    int countBinarySubstrings(string s) {
        
        int n = s.size();

        int ans = 0;
        int prev = 0;
        int current = 1;

        for(int i=1;i<n;i++)
        {
            if(s[i]!=s[i-1])
            {
                ans += min(prev,current);
                prev = current;
                current = 1;
            }
            else current++;
        }

        ans += min(prev,current);

        return ans;

    }
};