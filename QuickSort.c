#include <stdio.h>

void swap(int* p1, int* p2) {
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
while (1) {
// Find leftmost element greater than or equal to pivot
        do {i++;} while (arr[i] < pivot);
// Find rightmost element smaller than or equal to pivot
        do {j--;} while (arr[j] > pivot);
// two pointers meet
        if (i >= j)
            return j;

        swap(&arr[i], &arr[j]);
    }
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
