class Solution 
{
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> st;

        for(auto x : tokens)
        {
            if(x == "+" || x == "-" || x == "*" || x == "/")
            {
                int op1 = st.top(); st.pop();
                int op2 = st.top(); st.pop();

                if(x == "+") st.push(op2 + op1);
                else if (x == "-") st.push(op2 - op1);
                else if (x == "*") st.push(op2 * op1);
                else if (x == "/") st.push(op2 / op1);
            }

            else
            {
                st.push(stoi(x));
            }
        }

        return st.top();
    }
};



// stack<int> st;

//         for (auto x : tokens)
//         {
//             if (x == "+" || x == "-" || x == "*" || x == "/")
//             {
//                 int op1 = st.top(); st.pop();  // right operand
//                 int op2 = st.top(); st.pop();  // left operand

//                 if (x == "+") st.push(op2 + op1);
//                 else if (x == "-") st.push(op2 - op1);
//                 else if (x == "*") st.push(op2 * op1);
//                 else if (x == "/") st.push(op2 / op1);
//             }

//             else
//             {
//                 st.push(stoi(x));
//             }
//         }
        
//         return st.top();