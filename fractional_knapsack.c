#include <stdio.h>

struct Item {
    int val, wt;
    double r;
};

// greedy fractional knapsack
double fractional_knapsack(struct Item items[], int n, int cap) {
    // sort by ratio descending
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].r < items[j + 1].r) {
                struct Item t = items[j];
                items[j] = items[j + 1];
                items[j + 1] = t;
            }
        }
    }

    double total_val = 0.0;
    int cur_wt = 0;

    for (int i = 0; i < n; i++) {
        if (cur_wt + items[i].wt <= cap) {
            cur_wt += items[i].wt;
            total_val += items[i].val;
        } else {
            int rem = cap - cur_wt;
            total_val += items[i].val * ((double)rem / items[i].wt);
            break;
        }
    }
    return total_val;
}

int main() {
    int n, cap;
    struct Item items[100];
    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].val, &items[i].wt);
        items[i].r = (double)items[i].val / items[i].wt;
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &cap);

    double max_profit = fractional_knapsack(items, n, cap);
    printf("Maximum profit: %.2lf\n", max_profit);
    return 0;
}
