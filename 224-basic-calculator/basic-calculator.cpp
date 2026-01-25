class Solution 
{
public:

    int calculate(string s) 
    {
        stack<long long> st;

        long long result = 0, num = 0;
        int sign = 1;

        for (int i = 0; i < s.length(); i++) 
        {
            char ch = s[i];

            if (isdigit(ch)) 
            {
                num = num * 10 + (ch - '0');
            }


            else if (ch == '+' || ch == '-') 
            {
                result += sign * num;

                num = 0;

                sign = (ch == '+') ? 1 : -1;
            }

            else if (ch == '(') 
            {
                st.push(result);
                st.push(sign);

                result = 0;
                sign = 1;
            }

            else if (ch == ')') 
            {
                result += sign * num;

                num = 0;

                result *= st.top();
                st.pop();

                result += st.top();
                st.pop();
            }


        }

        result += sign * num;
        return (int)result;
    }
};

//  stack<long long> st;

//         long long result = 0, num = 0;
//         int sign = 1;

//         for (int i = 0; i < s.length(); i++)
//         {
//             char ch = s[i];

//             if (isdigit(ch))
//             {
//                 num = num * 10 + (ch - '0');
//             }

//             else if (ch == '+' || ch == '-')
//             {
//                 result += sign * num;

//                 num = 0;

//                 sign = (ch == '+') ? 1 : -1;
//             }

//             else if (ch == '(')
//             {
//                 st.push(result);
//                 st.push(sign);
//                 result = 0;
//                 sign = 1;
//             }

//             else if (ch == ')')
//             {
//                 result += sign * num;
//                 num = 0;

//                 result *= st.top(); // sign
//                 st.pop();

//                 result += st.top(); // previous result
//                 st.pop();
//             }
//         }

//         result += sign * num;
//         return (int)result;