#include "DP.h"
#include <stdlib.h>
#include <string.h> // For memset

int knapsackDP(int maxWeight, Item* items, int n) {
    // Allocate 2D array dynamically
    int** dp = (int**)malloc((n + 1) * sizeof(int*));
    for (int i = 0; i <= n; ++i) {
        dp[i] = (int*)malloc((maxWeight + 1) * sizeof(int));
        memset(dp[i], 0, (maxWeight + 1) * sizeof(int)); // Initialize with 0
    }

    // Dynamic Programming logic
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= maxWeight; ++w) {
            if (items[i - 1].weight > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                int includeItem = dp[i - 1][w - items[i - 1].weight] + items[i - 1].value;
                int excludeItem = dp[i - 1][w];
                dp[i][w] = (includeItem > excludeItem) ? includeItem : excludeItem;
            }
        }
    }

    // Get the result from the bottom-right corner
    int result = dp[n][maxWeight];

    // Free allocated memory
    for (int i = 0; i <= n; ++i) {
        free(dp[i]);
    }
    free(dp);

    return result;
}
