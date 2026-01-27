class MinStack 
{
public:
    stack<int> st , st2;

    MinStack() 
    {
        
    }
    
    void push(int val) 
    {
        if(st2.empty() || st2.top() >= val)
        {
            st2.push(val);
        }

        st.push(val);
    }
    
    void pop() 
    {
        if(st2.top() == st.top())
        {
            st2.pop();
        }

        st.pop();
    }
    
    int top() 
    {
        return st.top();
    }
    
    int getMin() 
    {
        return st2.top();
    }
};

// void push(int val) 
//     {
//         if( s2.empty() || val <= s2.top() )
//         {
//             s2.push(val);
//         }
        
//         st.push(val);
//     }
    
//     void pop() 
//     {
//         if(st.top() == s2.top())
//         {
//             s2.pop();
//         }

//         st.pop();
//     }
    

//     int top() 
//     {
//         return st.top();
//     }
    
    
//     int getMin() 
//     {
//         return s2.top();
//     }