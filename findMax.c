#include <stdio.h>
int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i=1; i<size; i++) {
        if(arr[i]>max) {
            max = arr[i];
        }
    }
    return max;
}
int main() {
    int arr[] = {5, 8,12, 3, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    // int max = findMax(arr, size);
    printf("maximum element in the array: %d\n", findMax(arr, size));
    return 0;
}