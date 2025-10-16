class Solution {
public:
    string convertDateToBinary(string date) {
        // Extract parts of the date
        string year = date.substr(0, 4);
        string month = date.substr(5, 2);
        string day = date.substr(8, 2);

        // Convert to integers
        int y = stoi(year);
        int m = stoi(month);
        int d = stoi(day);

        // Convert to binary strings
        return toBinary(y) + "-" + toBinary(m) + "-" + toBinary(d);
    }

private:
    string toBinary(int num) {
        string bin = "";
        while (num > 0) {
            bin = char('0' + (num % 2)) + bin;
            num /= 2;
        }
        return bin.empty() ? "0" : bin;
    }
};
