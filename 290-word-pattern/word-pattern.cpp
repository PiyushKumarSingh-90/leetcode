class Solution {
public:
    bool wordPattern(string pattern, string s) 
    {
        unordered_map<char, string> mapP; // Pattern character → word
        unordered_map<string, char> mapS; // Word → pattern character
        vector<string> words;
        string word;

        // Split 's' into words
        stringstream ss(s);
        while (ss >> word) words.push_back(word);

        // If number of words doesn't match pattern length, return false
        if (pattern.size() != words.size()) return false;

        for (int i = 0; i < pattern.size(); i++) 
        {
            char c = pattern[i];
            string w = words[i];

            // If already mapped, check if it matches
            if (mapP.count(c) && mapP[c] != w) return false;
            if (mapS.count(w) && mapS[w] != c) return false;

            // Otherwise, create a new mapping
            mapP[c] = w;
            mapS[w] = c;
        }

        return true;
    }
};