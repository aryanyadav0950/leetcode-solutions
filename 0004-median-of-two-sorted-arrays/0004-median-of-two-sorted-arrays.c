double findMedianSortedArrays(int* nums1, int m, int* nums2, int n) {
    int total = m + n;
    int mid = total / 2;

    int i = 0, j = 0;
    int prev = 0, curr = 0;

    for (int count = 0; count <= mid; count++) {
        prev = curr;

        if (i < m && j < n) {
            if (nums1[i] < nums2[j])
                curr = nums1[i++];
            else
                curr = nums2[j++];
        }
        else if (i < m) {
            curr = nums1[i++];
        }
        else {
            curr = nums2[j++];
        }
    }

    if (total % 2 == 1)
        return curr;

    return (prev + curr) / 2.0;
}