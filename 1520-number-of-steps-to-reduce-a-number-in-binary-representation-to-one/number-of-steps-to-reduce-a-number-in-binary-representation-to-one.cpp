class Solution {
public:

    string addOne(string binary) 
    {
        int n = binary.length();

        for(int i = n - 1; i >= 0; i--) 
        {
            if(binary[i] == '0') 
            {
                binary[i] = '1';
                return binary;   
            } 
            else 
            {
                binary[i] = '0'; 
            }
        }

        return "1" + binary;

    }

    int numSteps(string s) {

        int ans = 0;

        while(s.size()>1)
        {
            int n = s.size();

            if(s[n-1]=='0')
            {
                s.pop_back();
            }
            else
            {
                s = addOne(s);
            }
            ans++;
        }

        return ans;

    }
};