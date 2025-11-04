class Solution {
    public int mostWordsFound(String[] sentences) {
        int maxWords = 0;
        
        for (String sentence : sentences) {
            // Split by spaces and count words
            int wordCount = sentence.split(" ").length;
            // Update max if current is greater
            maxWords = Math.max(maxWords, wordCount);
        }
        
        return maxWords;
    }
}
