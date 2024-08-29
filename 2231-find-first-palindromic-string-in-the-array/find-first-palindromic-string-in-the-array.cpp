class Solution {
public:
    string firstPalindrome(vector<string>& words) 
    {
        for(int i=0; i<words.size();i++)
        {
            int n = words[i].size();
            bool isPalindrome = true;

            for(int j=0 ; j<n/2 ; j++)
            {
                if(words[i][j]!= words[i][n-j-1])
                {
                    isPalindrome = false;
                    break;
                }
            }

            if(isPalindrome==true)
            {
                return words[i];                
            }

            
        }

        return "";
    }
};