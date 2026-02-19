class Solution 
{
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
    {
        double ans;
        nums1.insert(nums1.end(),nums2.begin(),nums2.end());
        sort(nums1.begin(),nums1.end());
        if(nums1.size()%2!=0)
        {
            ans=nums1[(nums1.size()/2)];
        }
        else
        {
            // printf("%d %d",nums1[(nums1.size()/2)-1],nums1[nums1.size()/2]);
            int a=(nums1[(nums1.size()/2)-1]+nums1[nums1.size()/2]);
            ans=static_cast<double>(a)/2;
        }
        return ans;
    }
};