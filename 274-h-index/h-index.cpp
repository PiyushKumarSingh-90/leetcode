class Solution 
{
public:
    int hIndex(vector<int>& citations) 
    {
        sort(citations.rbegin(), citations.rend()); // Sort in descending order
         
        int h = 0;
        
        for (int i = 0; i < citations.size(); i++) 
        {
            if (citations[i] >= i + 1) // Check if at least (i+1) papers have (i+1) citations
                h++;
            else
                break;
        }
        
        return h;
    } 
};