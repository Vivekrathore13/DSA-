class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charcount(26, 0);
        
        // Count frequency of each character in 'chars'
        for (char &ch : chars) {
            charcount[ch - 'a']++;
        }

        int result = 0;

        for (string &word : words) {
            vector<int> wordcount(26, 0);

            // Count frequency of each character in 'word'
            for (char &wh : word) {
                wordcount[wh - 'a']++;
            }

            bool ok = true;

            // Check if word can be formed using chars
            for (int i = 0; i < 26; i++) {
                if (wordcount[i] > charcount[i]) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                result += word.length();
            }
        }

        return result;
    }
};
