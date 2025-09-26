class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> arr3;
        double median;
        
        int i=0,j=0;
        
        while(i<nums1.size() && j<nums2.size())
        {
            if(nums1[i]<nums2[j])
            {
                arr3.push_back(nums1[i++]);
            }
            else
            {
                arr3.push_back(nums2[j++]);
            }
        }

        while(i < nums1.size())
        {
            if(i< nums1.size())
            {
                arr3.push_back(nums1[i]);
                i++;
            }
        }

        while(j < nums2.size())
        {
            if(j< nums2.size())
            {
                arr3.push_back(nums2[j]);
                j++;
            }
        }


        if(arr3.size()%2==0)
        {
            median=(arr3[(arr3.size()/2)-1]+arr3[(arr3.size()/2)])/2.0;
        }

        else
        {
            median=arr3[arr3.size()/2];
        }

        return median;
            
    }
};