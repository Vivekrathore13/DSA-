/*
 * Time Complexity: O(n^2 * L), where n is the number of words, and L is the maximum length of a word.
 *   - Sorting takes O(n log n).
 *   - The DP loop checks each pair (i,j), and each predecessor check takes O(L) time.
 * Space Complexity: O(n), for the DP array t. Sorting uses O(1) extra space (in-place).
 */
class Solution {
public:
    // Helper function to check if 'prev' is a predecessor of 'curr' (curr is prev with exactly one extra character inserted)
    bool predecessor(string& prev, string& curr) {
        int m = prev.length();  // Length of previous string
        int n = curr.length();  // Length of current string
        
        // Quick check: prev must be exactly one character shorter than curr
        if (m >= n || n - m != 1)
            return false;
        
        int i = 0, j = 0;  // Pointers for prev and curr
        while (i < m && j < n) {  // Traverse both strings
            if (prev[i] == curr[j]) {  // If characters match, advance prev pointer
                i++;
            }
            j++;  // Always advance curr pointer (skipping one extra char in curr)
        }
        // All characters in prev must match a subsequence in curr
        return i == m;
    }
    
    // Static comparator function for sorting strings by length (ascending)
    static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();  // Shorter strings first to build chains progressively
    }
    
    // Main function to find the length of the longest string chain
    int longestStrChain(vector<string>& words) {
        int n = words.size();  // Number of words
        sort(begin(words), end(words), myFunction);  // Sort words by increasing length; pairs can be considered in any order, but this optimizes DP
        
        vector<int> t(n, 1);  // DP array: t[i] = length of longest chain ending at word i
        int maxL = 1;  // Track the maximum chain length found
        
        for (int i = 0; i < n; i++) {  // For each word as potential end of chain
            for (int j = 0; j < i; j++) {  // Check all previous words as potential predecessors
                
                if (predecessor(words[j], words[i])) {  // If words[j] precedes words[i]
                    t[i] = max(t[i], t[j] + 1);  // Extend the chain from j
                    maxL = max(maxL, t[i]);  // Update global maximum
                }
            }
        }
        
        return maxL;  // Return the length of the longest chain
    }
};