class Solution {
public:
    string intToRoman(int num) 
    {
         vector<pair<int, string>> values = {
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
            {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
            {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
            {1, "I"}
        };

        string result = "";
        
        // Loop through each pair in the values vector
        for (int i = 0; i < values.size(); i++) {
            int val = values[i].first;      // The integer value
            string rom = values[i].second;  // The corresponding Roman numeral

            // Keep subtracting val from num and add rom to result while num is large enough
            while (num >= val) {
                result += rom;  // Add Roman numeral to result
                num -= val;     // Subtract the value from num
            }
        }
        
        return result;
    }
};