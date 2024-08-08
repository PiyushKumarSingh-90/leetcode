class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        // int count=0;
        // int n=0;
        // int max=0;

        // for(int i=0; i<=nums.size(); i++)
        // {
        //     if(nums[i]==1)
        //     {
        //         n++;
        //     }

        //     else 
        //     {
        //        if(n>max)
        //         {
        //             max=n;
        //         }  
        //         n=0;               
        //     }
        // }

        // return max;

        int max=0;
        int n= nums.size();
        int ans=0;
        for(int i=0 ;i<n;i++)
        {
            if(nums[i]==1)
            ans++;
            else
            {
                if(max < ans)
                max=ans;
                ans=0;
            }
        }
        if(max<ans)
        max=ans;
        return max;
    }
};