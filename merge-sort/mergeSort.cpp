//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;



/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


// } Driver Code Ends
class Solution
{
    public:
    void merge(int arr[], int l, int m, int r)
    {
        // get the length of two parts of the array
        int len1 = m - l + 1 ;
        int len2 = r - m ;
        int totalLen = len1 + len2;
        // create two arrays 
        int *arr1 = new int[len1];
        int *arr2 = new int[len2];
        // put the values in them (to put the values subsequently an index for the parent arr is kept)
        int mainArrIndex = l ; // the starting point
        for(int i = 0 ; i < len1 ; i++){
            arr1[i] = arr[mainArrIndex++];
        }
        for(int i = 0; i < len2 ; i++){
            arr2[i] = arr[mainArrIndex++];
        }
        // now merge them
        int index1 = 0 ;
        int index2 = 0 ;
        //reset the main arrayIndex to l for replacing the values
        mainArrIndex = l;
        while(index1 < len1 && index2 < len2){
            if(arr1[index1] > arr2[index2]){
                arr[mainArrIndex++] = arr2[index2++];
            }
            else arr[mainArrIndex++] = arr1[index1++];
        }
        // add any left values in either arr1 or arr2
        while(index1 < len1){
            arr[mainArrIndex++] = arr1[index1++];
        }
        
        while(index2 < len2){
            arr[mainArrIndex++] = arr2[index2++];
        }
        delete []arr1;
        delete []arr2;
        return;
        
    }
    public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        merge(arr,l, mid, r);
    }
};

//{ Driver Code Starts.


int main()
{
    int n,T,i;

    scanf("%d",&T);

    while(T--){
    
    scanf("%d",&n);
    int arr[n+1];
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);

    Solution ob;
    ob.mergeSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
