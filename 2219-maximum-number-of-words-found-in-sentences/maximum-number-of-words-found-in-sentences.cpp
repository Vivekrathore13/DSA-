class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int ma = 0;
        for (auto sentence : sentences) {
            int words = 1; // at least one word
            for (char c : sentence) {
                if (c == ' ') words++;
            }
            ma = max(ma, words);
        }
        return ma;
    }
};
