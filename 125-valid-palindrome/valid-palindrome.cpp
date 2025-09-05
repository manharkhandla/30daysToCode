class Solution {
public:
    bool isPalindrome(string s) {
        string in = "";
        int n = s.size();

        for(int i=0;i<n;i++)
        {
            if (isalnum(s[i]))
            {               
                in += tolower(s[i]);       
            }
        }

        if(in.size()==0) return true;
        int st = 0;
        int end = in.size()-1;

        while(st<end)
        {
            if(in[st]!=in[end]) return false;
            st++;
            end--;
        }

        return true;
    }
};