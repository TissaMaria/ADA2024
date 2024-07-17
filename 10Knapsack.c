#include <stdio.h>
int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (wt[n - 1] > W)
        return knapSack(W, wt, val, n - 1);
    else
        return max(
            val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1),
            knapSack(W, wt, val, n - 1));
}
int main()
{
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);

    int profit[n], weight[n];
    printf("Enter the profit and weight for each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d: ", i + 1);
        scanf("%d %d", &profit[i], &weight[i]);
    }

    int W;
    printf("Enter the capacity of knapsack: ");
    scanf("%d", &W);

    printf("Maximum value in knapsack = %d\n", knapSack(W, weight, profit, n));
    return 0;
}
