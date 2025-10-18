class Solution {
    public boolean halvesAreAlike(String s) {
        int n = s.length();
        int mid = n / 2;
        int diff = 0;

        for (int i = 0; i < mid; i++) {
            if (isVowel(s.charAt(i))) diff++;
            if (isVowel(s.charAt(i + mid))) diff--;
        }

        return diff == 0;
    }

    private boolean isVowel(char c) {
        c = Character.toLowerCase(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
}
