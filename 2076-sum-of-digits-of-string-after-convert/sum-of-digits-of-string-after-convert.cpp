class Solution {
public:

   void getSum(string num,int k,int &ans1)
    {
        if(k==0) return;
        //cout<<num <<" " << ans <<" " << k << " " <<endl;
        int n = num.size();
        int ans = 0;
        for(int i=0;i<n;i++)
        {
            ans += num[i]-'0';
        }
        ans1 = ans;

        num = to_string(ans);
        //cout<<num <<" " << ans <<" " << k << " " <<endl;
        getSum(num,k-1,ans1);

        return;
    }

    int getLucky(string s, int k) {
        string num = "";
        int n = s.size();
        for(int i=0;i<n;i++)
        {
            num += to_string(s[i] - 'a' + 1);
        }

        cout<<num<<endl;
        int ans = 0;
        int ans1 = ans;
        getSum(num,k,ans1);

        return ans1;
    }

};