#include <stdio.h>
int main() {
    // int numbers[5]={1, 2, 3, 4,5};
    // for(int i=0; i<5; i++) {
    //     printf("%d", numbers[i]);
    //     printf("\n");
    // }
    int arr[10]={[0]=89, [7]=94, [5]=6};
    printf("array elements: ");
    for (int i=0; i<10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}