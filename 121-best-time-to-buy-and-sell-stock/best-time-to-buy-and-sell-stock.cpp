class Solution 
{
public:
    int maxProfit(vector<int>& prices) 
    {
        int lowest = prices[0];  
        int maxProfit = 0;  

        for (int i = 1; i < prices.size(); i++) 
        {  
            if (prices[i] < lowest) 
            {  
                lowest = prices[i];  // Update lowest price
            } 
            
            else 
            {  
                int profit = prices[i] - lowest;  

                if (profit > maxProfit) 
                {  
                    maxProfit = profit;  // Update max profit
                }  
            }  
        }

        return maxProfit;
    }
};