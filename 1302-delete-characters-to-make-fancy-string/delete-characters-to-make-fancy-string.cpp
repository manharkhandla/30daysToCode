class Solution {
public:
    string makeFancyString(string s) {
        int n = s.size();
        string ans = "";

        if(n==1) return s;
        ans += s[0];
        int ss ;
        for(int i=1;i<n;i++)
        {
            ss = ans.size();
            if(ans.size()>=2 && s[i]==ans[ss-1] && s[i]==ans[ss-2])
            {
                continue;
            }
            else
            { 
                ans += s[i];
            }
        }
        return ans;
    }
};