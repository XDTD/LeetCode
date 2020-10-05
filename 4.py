def findMedium(nums:list):
    mid = int((1+len(nums))/2)-1
    return (nums[mid]+nums[mid+(1+len(nums))%2])/2



def findMedianSortedArrays(self,nums1: List[int],nums2: List[int]) -> float:
    if len(nums1) == 0:
        return findMedium(nums2)
    if len(nums2)==0:
        return findMedium(nums1)
    if len(nums2)==1 and len(nums1)==1:
        return findMedium(nums1+nums2)
    mid = (len(nums1)+len(nums2))/2
    mid1 = int((1+len(nums1))/2)-1
    mid2 = int((1 + len(nums2)) / 2)-1
    if nums1[mid1+1] > nums2[mid2] or nums2[mid2+1] > nums1[mid1]:
        if mid2+mid1+1<mid:
            return findMedianSortedArrays(nums1[:mid1], nums2[:mid2])
        else:
            return findMedianSortedArrays(nums1[mid1+1:],nums2[mid2+1:])
    elif nums2[-1]<nums1[0]:
        if len(nums2)>mid:
            return findMedianSortedArrays(n)
        







