class Solution {
public:
    int calculate(string s) 
    {
        stack<int> st;
        int result = 0, num = 0, sign = 1; // sign = 1 for '+', -1 for '-'

        // Using a traditional for loop instead of range-based for loop
        for (int i = 0; i < s.length(); i++) 
        {
            char ch = s[i]; // Get the current character
            
            if (isdigit(ch)) 
            {
                num = num * 10 + (ch - '0'); // Build the number
            } 
            else if (ch == '+' || ch == '-') 
            {
                result += sign * num; // Apply previous number
                num = 0; // Reset num

                // Update sign using if-else for better readability
                if (ch == '+') 
                {
                    sign = 1;
                } 
                else 
                {
                    sign = -1;
                }
            } 
            else if (ch == '(') 
            {
                st.push(result);  // Store current result
                st.push(sign);    // Store current sign
                result = 0;       // Reset for new expression inside ()
                sign = 1;         // Reset sign
            } 
            else if (ch == ')') 
            {
                result += sign * num; // Apply last number inside ()
                num = 0;
                result *= st.top(); // Apply the sign before '('
                st.pop();
                result += st.top(); // Add the result before '('
                st.pop();
            }
        }

        return result + (sign * num); // Add last number to result
    }
};