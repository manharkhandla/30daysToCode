class Solution {
public:

    bool isPal(string &s,int i,int j)
    {
        if(i>=j) return true;

        if(s[i]==s[j]) return isPal(s,i+1,j-1);

        return false;
    }

    string longestPalindrome(string s) {
        int n = s.size();
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