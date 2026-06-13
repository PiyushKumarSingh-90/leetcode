class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        int len = s.size();
        
        char seen[128] = {0};
        
        for (int i = 0; i < len; i++) 
        {
            char c = s[i];

            if (seen[c] == 0) 
            {
                for (char x: seen) 
                {
                    if (x == t[i]) return false;
                }
                
                seen[c] = t[i];
            }

            else if (seen[c] != t[i]) return false;
        }

        return true;
    }
};