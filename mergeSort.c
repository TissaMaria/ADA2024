#include <stdio.h>
#include <stdlib.h>

void Merge(int A[], int l, int mid, int h) {
    int i, j, k;
    int B[100];
    i = l;
    j = mid + 1;
    k = l;

    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    for (; i <= mid; i++) {
        B[k++] = A[i];
    }
    for (; j <= h; j++) {
        B[k++] = A[j];
    }
    for (i = l; i <= h; i++) {
        A[i] = B[i];
    }
}

void MergeSort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        MergeSort(A, l, mid);      // first half
        MergeSort(A, mid + 1, h);  // second half
        Merge(A, l, mid, h);       // merge
    }
}

int main() {
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int A[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
    printf("Original array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    MergeSort(A, 0, n - 1);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return 0;
}
