class Solution 
{
public:
    int candy(vector<int>& ratings) 
    {
        int candies = 0;
        int n = ratings.size();
        vector<int> candyDist(n, 1); // Every child gets at least 1 candy

        for (int i = 1; i < n; i++) // Left to Right Pass
        {
            if (ratings[i] > ratings[i - 1]) 
            {
                candyDist[i] = candyDist[i - 1] + 1;
            }
        }

        for (int i = n - 2; i >= 0; i--) // Right to Left Pass
        {
            if (ratings[i] > ratings[i + 1]) 
            {
                candyDist[i] = max(candyDist[i], candyDist[i + 1] + 1);
            }
        }

        for (int i = 0; i < n; i++) // Compute Total Candies
        {
            candies += candyDist[i];
        }

        return candies;
    }
};