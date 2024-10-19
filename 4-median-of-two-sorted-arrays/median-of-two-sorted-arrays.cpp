class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> arr3;
        double median;

        int n1=nums1.size(), n2=nums2.size();

        int i=0,j=0;
        
        while(i<n1 && j<n2)
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

        while(i < n1)
        {
            if(i< n1)
            {
                arr3.push_back(nums1[i]);
                i++;
            }
        }

        while(j < n2)
        {
            if(j< n2)
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