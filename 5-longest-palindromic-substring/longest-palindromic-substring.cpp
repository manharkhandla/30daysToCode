class Solution {
public:
    int t[1001][1001];
    bool isPal(string &s,int i,int j)
    {
        if(i>=j) return 1;

        if(t[i][j] != -1) return t[i][j];

        if(s[i]==s[j]) return t[i][j] = isPal(s,i+1,j-1);

        return t[i][j] = 0;
    }

    string longestPalindrome(string s) {
        int n = s.size();
        memset(t,-1,sizeof(t));
        int maxlength = 0;
        int sp = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPal(s,i,j))
                {
                    if(j-i+1>maxlength)
                    {
                        maxlength = j-i+1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp,maxlength);
    }
};