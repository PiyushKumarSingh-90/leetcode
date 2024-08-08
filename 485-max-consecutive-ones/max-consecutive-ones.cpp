class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int n=0;
        int a=nums.size();
        int max=0;

        for(int i=0; i<a; i++)
        {
            if(nums[i]==1)
            n++;
            else 
            {
               if(max<n)
               { 
                max=n;
               }

                n=0;      
                                                
            }
        
        }
        
        if(max<n)
        {
           max=n; 
        }

        return max;

        
    
    }
};