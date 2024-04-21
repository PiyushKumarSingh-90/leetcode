class Solution 
{
public:
    vector<int> shuffle(vector<int>& nums, int n) 
    {
       n=nums.size()/2; 
       vector<int>arr(nums.size());

       for(int i=0;i<n;i++)
       {
            arr[i*2]= nums[i];
            arr[(i+i)+1]=nums[n+i];
       }
       return arr;

    }
};