class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n1 = s.size();
        int n2 = t.size();

        stack<char> st1;
        stack<char> st2;

        string s1 = "";
        string s2 = "";

        for(int i=0;i<n1;i++)
        {
            if(s[i]=='#' && st1.empty()) continue;
            else if(s[i]=='#')
            {
                st1.pop();
            }
            else st1.push(s[i]);
        }

        for(int i=0;i<n2;i++)
        {
            if(t[i]=='#' && st2.empty()) continue;
            else if(t[i]=='#')
            {
                st2.pop();
            }
            else st2.push(t[i]);
        }
        
        if(st1.size()==0 && st2.size()==0) return true;
        else if(st1.size()!=st2.size()) return false;
        else
        {
            // while(!st1.empty() && !st2.empty() && st1.top()==st2.top())
            // {
            //     st1.pop();
            //     st2.pop();
            //     flag = true;
            // }

            int sz = st1.size();
            for(int i=0;i<sz;i++)
            {
                if(st1.top()!=st2.top()) return false;
                st1.pop();
                st2.pop();
            }
            return true;
        }

        return false;
    }
};