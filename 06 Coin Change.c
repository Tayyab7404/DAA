#include <stdio.h>
#include <limits.h>

int CoinChange(int coins[], int n, int amount);

int main()
{
    int n, amount;

    printf("Enter the number of denominations: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter the denominations: ");
    for (int i=0; i<n; i++)
        scanf("%d", &coins[i]);

    printf("Enter the amount of money: ");
    scanf("%d", &amount);

    int coinsReq = CoinChange(coins, n, amount);

    printf("Required number of coins: %d\n", coinsReq);
}

int CoinChange(int coins[], int n, int amount)
{
    int dp[amount+1];
    dp[0] = 0;

    for (int i=1; i<=amount; i++)
        dp[i] = INT_MAX;

    for (int i=1; i<=amount; i++)
        for (int coin=0; coin<n; coin++)
            if (coins[coin] <= i)
                dp[i] = (1+dp[i-coins[coin]]) < dp[i] ? (1+dp[i-coins[coin]]) : dp[i];

    return dp[amount];
}
