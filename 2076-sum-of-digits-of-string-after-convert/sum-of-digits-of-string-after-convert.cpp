class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        int n = s.size();

        for (int i=0;i<n;i++) {
            num += to_string(s[i] - 'a' + 1);
        }

        
        while (k--) {
            int sum = 0;
            int d = num.size();
            for (int i=0;i<d;i++) {
                sum += num[i] - '0';
            }
            num = to_string(sum);
        }

        return stoi(num);
    }
};
