class Solution {
public:

    char solve(vector<char> temp,char opr)
    {
        if(opr == '!')
        {
            return temp[0] == 't' ? 'f' : 't';
        }

        if(opr == '&')
        {
            for(char &ch : temp)
            {
                if(ch=='f') return 'f';
            }
            return 't';
        }

        if(opr == '|')
        {
            for(char &ch : temp)
            {
                if(ch=='t') return 't';
            }
            return 'f';
        }

        return 'f';
    }

    bool parseBoolExpr(string expression) {
        int n = expression.size();

        stack<char> st;

        for(int i=0;i<n;i++)
        {
            if(expression[i]==',') continue;

            if(expression[i]==')')
            {
                vector<char> temp;

                while(st.top()!='(')
                {
                    temp.push_back(st.top());
                    st.pop();
                }

                st.pop();
                char opr = st.top();
                st.pop();

                st.push(solve(temp,opr));
            }
            else
            {
                st.push(expression[i]);
            }
        }

        return st.top() == 't' ? true : false;
    }
};