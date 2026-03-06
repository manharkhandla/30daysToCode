class Solution {
public:
    bool checkOnesSegment(string s) {

        int n = s.size();

        bool seenZero = false;

        for(int i=1;i<n;i++)
        {
            if(s[i]=='0') seenZero = true;
            if(seenZero && s[i]=='1') return false;
        }

        return true;

    }
};