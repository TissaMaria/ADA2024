#include <stdio.h>
#include <stdbool.h>

#define LEFT_TO_RIGHT 1
#define RIGHT_TO_LEFT 0

void printPermutation(int *permutation, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", permutation[i]);
    }
    printf("\n");
}
int getMobile(int *permutation, bool *direction, int n) {
    int mobile_prev = 0, mobile = 0;

    for (int i = 0; i < n; i++) {
        if (direction[permutation[i] - 1] == RIGHT_TO_LEFT && i != 0) {
            if (permutation[i] > permutation[i - 1] && permutation[i] > mobile_prev) {
                mobile = permutation[i];
                mobile_prev = mobile;
            }
        }

        if (direction[permutation[i] - 1] == LEFT_TO_RIGHT && i != n - 1) {
            if (permutation[i] > permutation[i + 1] && permutation[i] > mobile_prev) {
                mobile = permutation[i];
                mobile_prev = mobile;
            }
        }
    }

    if (mobile == 0 && mobile_prev == 0) {
        return 0;
    } else {
        return mobile;
    }
}

void johnsonTrotter(int n) {
    int permutation[n];
    bool direction[n];

    for (int i = 0; i < n; i++) {
        permutation[i] = i + 1;
        direction[i] = RIGHT_TO_LEFT;
    }
    printPermutation(permutation, n);

    while (true) {
        int mobile = getMobile(permutation, direction, n);

        if (mobile == 0) {
            break;
        }

        int pos;
        for (int i = 0; i < n; i++) {
            if (permutation[i] == mobile) {
                pos = i;
                break;
            }
        }

        if (direction[permutation[pos] - 1] == RIGHT_TO_LEFT) {
            int temp = permutation[pos];
            permutation[pos] = permutation[pos - 1];
            permutation[pos - 1] = temp;
        } else if (direction[permutation[pos] - 1] == LEFT_TO_RIGHT) {
            int temp = permutation[pos];
            permutation[pos] = permutation[pos + 1];
            permutation[pos + 1] = temp;
        }
        for (int i = 0; i < n; i++) {
            if (permutation[i] > mobile) {
                direction[permutation[i] - 1] = !direction[permutation[i] - 1];
            }
        }
        printPermutation(permutation, n);
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    johnsonTrotter(n);

    return 0;
}
