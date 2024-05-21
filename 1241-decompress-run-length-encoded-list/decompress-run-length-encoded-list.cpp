class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) 
    {
        vector<int>decompressed;

        int freq,val;

        for(int i=0 ; i<nums.size()/2 ; i++)
        {
            freq=nums[2*i];
            val=nums[2*i+1];

            for(int j=0 ; j<freq ; j++ )
            {
                decompressed.push_back(val);
            }
        }

        return decompressed;

        

    }
};