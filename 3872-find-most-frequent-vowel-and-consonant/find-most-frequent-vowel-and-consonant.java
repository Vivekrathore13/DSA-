class Solution {
    public int maxFreqSum(String s) {
        int[] freq = new int[26];
        for (char ch : s.toCharArray()) {
            freq[ch - 'a']++;
        }

        int maxVowelFreq = 0, maxConsonantFreq = 0;
        String vowels = "aeiou";

        for (int i = 0; i < 26; i++) {
            char c = (char) (i + 'a');
            if (freq[i] > 0) {
                if (vowels.indexOf(c) != -1) { 
                    // It's a vowel
                    maxVowelFreq = Math.max(maxVowelFreq, freq[i]);
                } else {
                    // It's a consonant
                    maxConsonantFreq = Math.max(maxConsonantFreq, freq[i]);
                }
            }
        }

        return maxVowelFreq + maxConsonantFreq;
    }
}
