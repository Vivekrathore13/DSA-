class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);           // Convert int to string
        for (char &c : s) {                  // Loop through characters
            if (c == '6') {                  // Replace first '6' with '9'
                c = '9';
                break;
            }
        }
        return stoi(s);                      // Convert back to int
    }
};
