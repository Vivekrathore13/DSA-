class Solution {
public:
    int strStr(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        if (m == 0) return 0;

        for (int i = 0; i <= n - m; i++) {
            int j;
            for (j = 0; j < m; j++) {
                if (s1[i + j] != s2[j])
                    break;
            }
            if (j == m)  // all characters matched
                return i;
        }
        return -1;
    }
};
