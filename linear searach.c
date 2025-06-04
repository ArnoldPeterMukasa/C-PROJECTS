#include <stdio.h>
int linearsearch(int arr[], int size, int target) {
    for (int i=0; i<size; i++) {
        if (arr[i]==target) {
            return i; // return index of the found element
        }
    }
    return -1; //reutrn -1 if the element is not found
}
int main(){
    int arr[]={3,7,10,20,13,67,89};
    int size= sizeof(arr)/sizeof(arr[0]);
    int target =89;
    int result = linearsearch(arr,size,target);
    if(result!=-1) 
            printf("element found at index %d\n", result);
    else
        printf("element not found");
    return 0;
}