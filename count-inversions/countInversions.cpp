#include <bits/stdc++.h>

long long merge(long long *arr, long long l, long long m, long long r) {
    // Get the length of two parts of the array
    long long len1 = m - l + 1;
    long long len2 = r - m;
    long long count = 0;
    
    // Create two arrays
    long long *arr1 = new long long[len1];
    long long *arr2 = new long long[len2];
    
    // Copy the values into the temporary arrays
    for (long long i = 0; i < len1; i++) {
        arr1[i] = arr[l + i];
    }
    for (long long i = 0; i < len2; i++) {
        arr2[i] = arr[m + 1 + i];
    }
    
    // Merge the arrays
    long long i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (arr1[i] <= arr2[j]) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
            count += (len1 - i);  // Count the inversions
        }
    }
    
    // Copy any remaining elements of arr1
    while (i < len1) {
        arr[k++] = arr1[i++];
    }
    
    // Copy any remaining elements of arr2
    while (j < len2) {
        arr[k++] = arr2[j++];
    }
    
    delete[] arr1;
    delete[] arr2;
    return count;
}

long long mergeSort(long long *arr, long long l, long long r) {
    long long count = 0;
    if (l < r) {
        long long m = l + (r - l) / 2;
        count += mergeSort(arr, l, m);
        count += mergeSort(arr, m + 1, r);
        count += merge(arr, l, m, r);
    }
    return count;
}

long long getInversions(long long *arr, long long n) {
    return mergeSort(arr, 0, n - 1);
}
