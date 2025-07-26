class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        int prev = 0;
        if(n==1) return s;

        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                reverse(s.begin()+prev,s.begin()+i);
                prev = i+1;
            }
            else if(i==n-1)
            {
                reverse(s.begin()+prev,s.end());
            }
        }
        return s;
    }
};