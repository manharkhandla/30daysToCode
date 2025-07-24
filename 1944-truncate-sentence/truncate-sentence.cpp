class Solution {
public:
    string truncateSentence(string s, int k) {
        int i = 0;
        int n = s.length();
        string ans = "";


        for(int i=0;i<n;i++)
        {
            if(s[i]==' ')
            {
                k--;
            }
            if(k==0) break;
            ans += s[i];
        }


        // while(k)
        // {
        //     if(s[i]==' ')
        //     {
        //         k--;
        //     }
        //     ans += s[i];
        //     i++;
        // }

        return ans;
    }
};