#include<stdio.h>

int main()
{
    int userCoin = 128;
    int fiveCoin = 0, twoCoin = 0, oneCoin = 0;

    printf("Please input the Coins Values:");
    scanf("%d", &userCoin);

    if(userCoin < 0)
    {
        printf("Input Error!\n");
        return 0;
    }
    while(userCoin >= 5)
    {
        userCoin = userCoin - 5;
        fiveCoin++;
    }
    while(userCoin >= 2)
    {
        userCoin = userCoin - 2;
        twoCoin++;
    }
    while(userCoin >= 1)
    {
        userCoin = userCoin - 1;
        oneCoin++;
    }

    printf("5元硬币数=%d\n", fiveCoin);
    printf("2元硬币数=%d\n", twoCoin);
    printf("1元硬币数=%d\n", oneCoin);

    return 0;
}