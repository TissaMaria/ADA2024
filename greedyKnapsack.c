#include <stdio.h>
#include <stdlib.h>
struct Item {
    int profit;
    int weight;
};

// to sort item according to profit/weight ratio
int cmp(const void *a, const void *b) {
    struct Item *itemA = (struct Item *)a;
    struct Item *itemB = (struct Item *)b;
    double r1 = (double)itemA->profit / (double)itemA->weight;
    double r2 = (double)itemB->profit / (double)itemB->weight;
    return r2 > r1 ? 1 : -1;
}

double fractionalKnapsack(int W, struct Item arr[], int N) {
    qsort(arr, N, sizeof(struct Item), cmp);

    double finalvalue = 0.0;
    for (int i = 0; i < N; i++) {
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].profit;
        }
        // can't add current Item? add fractional part of it
        else {
            finalvalue += arr[i].profit * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
int main() {
    int W, N;
    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);
    printf("Enter the number of items: ");
    scanf("%d", &N);

    struct Item *arr = (struct Item *)malloc(N * sizeof(struct Item));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter the profit and weight of each item (format: profit weight):\n");
    for (int i = 0; i < N; i++) {
        scanf("%d %d", &arr[i].profit, &arr[i].weight);
    }

    double maxProfit = fractionalKnapsack(W, arr, N);
    printf("Maximum profit in knapsack = %.2f\n", maxProfit);

    free(arr);
    return 0;
}
