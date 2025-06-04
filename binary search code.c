#include <stdio.h>
int binarySearch(int arr[], int left, int right, int target){
    while (left<=right){
         int mid = left + (right-left)/2 ;
         if (arr[mid]==target) 
            return mid;
         else if (arr[mid]<target) 
            left = mid+1;
         else
             right = mid-1;                                                        
    }
    return -1;
}
int main(){
    int arr[]={23,25,29,35,40,49,67,72,79,87};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target=81;
    int result = binarySearch(arr,0,size-1,target);
    if(result!=-1)
         printf("target at index %d\n", result);
    else
        printf("target not found\n");
    return 0;
}