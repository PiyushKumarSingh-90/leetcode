class Solution 
{
public:
    bool isAnagram(string s, string t) 
    {
        unordered_map<char, int> ma;
        unordered_map<char, int> mb;
        
        for(const auto &el: s)
        {
            ma[el]++;
        }
        
        for(const auto &el: t)
        {
            mb[el]++;
        }
        
        return ma == mb;
    }
};