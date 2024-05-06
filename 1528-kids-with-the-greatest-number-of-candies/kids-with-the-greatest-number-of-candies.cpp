class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) 
    {
        vector<bool> result;
        int greatest=0;

        for(int i=0;i<candies.size();i++)
        {
            if(candies[i]>greatest)
            {
                greatest=candies[i];
            }
        }

        for(int i=0;i<candies.size();i++)
        {
            if(greatest<=candies[i]+extraCandies )
            {
                result.push_back(true);
            }
            else
            {
                result.push_back(false);
            }
        }
       return result; 
    }
    
};