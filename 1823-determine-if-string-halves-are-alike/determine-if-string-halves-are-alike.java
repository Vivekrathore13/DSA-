class Solution {
    public boolean halvesAreAlike(String s) {
        int n = s.length();
        int i = 0;
        int j = n / 2;
        int ans = 0, count = 0;

        // fixed loop condition (was wrong)
        while (i < n / 2 && j < n) {
            if (s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || s.charAt(i) == 'u' ||
                s.charAt(i) == 'A' || s.charAt(i) == 'E' || s.charAt(i) == 'I' || s.charAt(i) == 'O' || s.charAt(i) == 'U') {
                ans++;
            }

            if (s.charAt(j) == 'a' || s.charAt(j) == 'e' || s.charAt(j) == 'i' || s.charAt(j) == 'o' || s.charAt(j) == 'u' ||
                s.charAt(j) == 'A' || s.charAt(j) == 'E' || s.charAt(j) == 'I' || s.charAt(j) == 'O' || s.charAt(j) == 'U') {
                count++;
            }

            i++;
            j++;
        }

        if (ans == count)
            return true;
        else
            return false;
    }
}
