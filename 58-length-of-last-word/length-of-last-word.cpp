class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int i;
        for(i=s.size()-1;i>=0;i--)
        {
            if(s[i]!=' ') break;
        }

        s.erase(i+1);

        int j = s.size()-1;
        while(j>=0 && s[j]!=' ')
        {
            j--;
            ans++;
        }

        return ans;
    }
};