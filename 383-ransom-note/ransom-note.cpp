class Solution 
{
public:
    bool canConstruct(string ransomNote, string magazine) 
    {
        vector<int> count(26, 0); // Array to store letter frequencies

        // Count letters in magazine
        for (char ch : magazine) 
        {
            count[ch - 'a']++;
        }

        // Check if ransomNote can be formed
        for (char ch : ransomNote) 
        {
            if (count[ch - 'a'] == 0) 
            {
                return false; // Letter missing
            }
            count[ch - 'a']--; // Use the letter
        }

        return true;
    }
};