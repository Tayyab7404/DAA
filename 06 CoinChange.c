#include<stdio.h>

int CoinChange(int coins[], int n, int amount);

int main()
{
    int n;
    printf("Enter number of denominations: ");
    scanf(" %d", &n);

    int coins[n];
    printf("Enter the denominations: ");
    for(int i=0; i<n; i++)
        scanf(" %d", &coins[i]);

    int amount;
    printf("Enter the amount: ");
    scanf(" %d", &amount);

    int ReqCoins = CoinChange(coins, n, amount);

    printf("Required number of coins = %d\n", ReqCoins);

    return 0;
}

int CoinChange(int coins[], int n, int amount)
{
    

    return 0;
}