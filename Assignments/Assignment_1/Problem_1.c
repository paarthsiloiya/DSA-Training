#include <stdio.h>

int maxProfitOne(int prices[], int n) {
    int minPrice = prices[0];
    int maxProfit = 0;
    for (int i = 1; i < n; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}

int maxProfitTwo(int prices[], int n) {
    if (n == 0) return 0;
    int leftProfit[n];
    int minPrice = prices[0];
    leftProfit[0] = 0;
    for (int i = 1; i < n; i++) {
        minPrice = (prices[i] < minPrice) ? prices[i] : minPrice;
        leftProfit[i] = (prices[i] - minPrice > leftProfit[i-1]) ? prices[i] - minPrice : leftProfit[i-1];
    }
    int rightProfit[n];
    int maxPrice = prices[n-1];
    rightProfit[n-1] = 0;
    for (int i = n-2; i >= 0; i--) {
        maxPrice = (prices[i] > maxPrice) ? prices[i] : maxPrice;
        rightProfit[i] = (maxPrice - prices[i] > rightProfit[i+1]) ? maxPrice - prices[i] : rightProfit[i+1];
    }
    int maxP = 0;
    for (int i = 0; i < n; i++) {
        if (leftProfit[i] + rightProfit[i] > maxP) {
            maxP = leftProfit[i] + rightProfit[i];
        }
    }
    return maxP;
}

int main() {
    int n;
    printf("Enter the number of days: ");
    scanf("%d", &n);
    int prices[n];
    printf("Enter the stock prices for %d days:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &prices[i]);
    }
    int profitOne = maxProfitOne(prices, n);
    int profitTwo = maxProfitTwo(prices, n);
    printf("Maximum profit with one transaction: %d\n", profitOne);
    printf("Maximum profit with at most two transactions: %d\n", profitTwo);
    return 0;
}