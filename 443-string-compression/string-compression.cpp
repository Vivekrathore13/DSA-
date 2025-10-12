class Solution {
public:
    int compress(vector<char>& chars) {
        // Get the size of the input vector
        int n = chars.size();
        // 'index' tracks the position to write the next character in the compressed result
        int index = 0;
        // 'i' is the iterator for traversing the input vector
        int i = 0;
        
        // Traverse the vector until we reach the end
        while (i < n) {
            // Capture the current character to be compressed
            char currchar = chars[i];
            // Count the frequency of the current character
            int count = 0;
            
            // Inner loop to count consecutive occurrences of the current character
            while (i < n && chars[i] == currchar) {
                count++;
                i++;
            }
            
            // Write the current character to the result position
            chars[index] = currchar;
            index++;
            
            // If the count is greater than 1, append the count as string
            if (count > 1) {
                // Convert count to string for appending digits
                string countstr = to_string(count);
                
                // Append each digit of the count to the result
                for (char &ch : countstr) {
                    chars[index] = ch;
                    index++;
                }
            }
        } 
        
        // Return the length of the compressed string
        return index;
    }
};

/*
Time Complexity (TC): O(N), where N is the length of the input vector.
We traverse the vector exactly once with the outer and inner while loops combined.

Space Complexity (SC): O(1), as we modify the input vector in-place.
The temporary string created by to_string(count) uses O(log N) space in the worst case,
but this is typically considered constant extra space since log N is small.
*/